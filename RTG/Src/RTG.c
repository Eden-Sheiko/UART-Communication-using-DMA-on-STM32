/**
 * @file main.c
 * @brief Example of UART communication using DMA on STM32
 * This example uses UART 4 (PC10 TX, PC11 RX)
 * as Master and USART 6 (PC6 TX, PC7 RX) as Slave.
 */

#include "RTG.h"
#include <inttypes.h>

#define BUFFER_SIZE sizeof(pocket_t)
#define DATA_TRANSFER_ID 2
#define DATA_TRANSFER_INTERVAL 1000

/**
 * @brief Flag indicating successful UART slave callback
 */
volatile uint8_t uart_slave_callback_success = 0;

/**
 * @brief Flag indicating successful UART master callback
 */
volatile uint8_t uart_master_callback_success = 0;

/**
 * @brief Buffer for sending data
 */
uint8_t buffer_send[BUFFER_SIZE] = {0};

/**
 * @brief Buffer for receiving data from slave UART
 */
uint8_t buffer_receive_slave[BUFFER_SIZE] = {0};

/**
 * @brief Buffer for receiving data from master UART
 */
uint8_t buffer_receive_master[BUFFER_SIZE] = {0};

/**
 * @brief Pocket for data transfer
 */
pocket_t t1 = {0};

/**
 * @brief Function to print content of the pocket.
 * @param pocket Pointer to the pocket structure.
 * PRIu32 - is being used for disable the uint32 warning
 */
void print_pocket_content(pocket_t* pocket) {
    printf("Pocket content:\n");
    printf("ID: %" PRIu32 "\n", pocket->m_id);
    printf("Padding: %s\n", pocket->m_padding);
}

/**
 * @brief Function to compare two pockets.
 * @param pocket1 Pointer to the first pocket.
 * @param pocket2 Pointer to the second pocket.
 * @return 1 if pockets are identical, 0 otherwise.
 */
uint8_t compare_pockets(pocket_t* pocket1, pocket_t* pocket2) {
    if (pocket1->m_id != pocket2->m_id) {
        return 0;
    }

    if (memcmp(pocket1->m_padding, pocket2->m_padding, PADDING) != 0) {
        return 0;
    }

    return 1;
}

/**
 * @brief Main function.
 * Sets up data transfer and handles data sending and receiving.
 */
void rtg_main() {
	while (1) {
		t1.m_id = DATA_TRANSFER_ID;
		memset(t1.m_padding, '0', sizeof(t1.m_padding));
		memcpy(buffer_send, &t1, sizeof(t1));

		HAL_UART_Receive_DMA(UART_SLAVE, buffer_receive_slave, BUFFER_SIZE);
		HAL_UART_Transmit_DMA(UART_MASTER, buffer_send, BUFFER_SIZE);

		HAL_UART_Receive_DMA(UART_MASTER, buffer_receive_master, BUFFER_SIZE);
		HAL_UART_Transmit_DMA(UART_SLAVE, buffer_send, BUFFER_SIZE);

		HAL_Delay(DATA_TRANSFER_INTERVAL);

		if (uart_slave_callback_success) {
			printf("Data_Sent:\r\n");
			printf("%s\r\n", buffer_send);

            print_pocket_content(&t1);

			HAL_UART_Receive_DMA(UART_MASTER, buffer_receive_master, BUFFER_SIZE);
			HAL_UART_Transmit_DMA(UART_SLAVE, buffer_send, BUFFER_SIZE);
			uart_slave_callback_success = 0;
		}

		if (uart_master_callback_success) {
			printf("Data_Received from Master:\r\n");
			printf("%s\r\n", buffer_receive_master);

            pocket_t received_pocket;
            memcpy(&received_pocket, buffer_receive_master, BUFFER_SIZE);
            print_pocket_content(&received_pocket);

            if (compare_pockets(&t1, &received_pocket) == 0) {
                printf("Warning: Sent and received data do not match.\n");
            }

			uart_master_callback_success = 0;
		}
	}
}

/**
 * @brief UART Receive Complete callback function.
 * This function is called when the reception of data via UART is complete.
 * @param huart Pointer to the UART handle.
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == UART_SLAVE) {
		uart_slave_callback_success = 1;
	}

	if (huart == UART_MASTER) {
		uart_master_callback_success = 1;
	}
}
