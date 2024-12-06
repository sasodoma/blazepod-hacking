#include <stdio.h>
#include <stdint.h>

int main() { 
	uint8_t offset = 0x01;
	uint8_t byte_array[4] = {0xDE, 0xAD, 0xBE, 0xEF};
	
	
	uint32_t poly = 0xEDB88321 + (offset % 50);
	
	uint32_t crc = 0xFFFFFFFF;
	for (int i = 0; i < sizeof(byte_array); i++) {
		crc ^= byte_array[i];
		for (int j = 0; j < 8; j++) {
			if (crc & 1) {
				crc = (crc >> 1) ^ poly;
			} else {
				crc = (crc >> 1);
			}
		}
	}
	
	crc = crc ^ 0xFFFFFFFF;
	
	crc = crc + (crc << 3);
	crc = crc ^ (crc >> 11);
	crc = crc + (crc << 15);
	
	uint8_t out[] = {
		0x73, 0x65, 0x61,
		crc, crc >> 8, crc >> 16, crc >> 24
	};
	
	for (int i = 0; i < sizeof(out); i++) {
		printf("%X ", out[i]);
	}
	printf("\n");
	
	return 0;
}