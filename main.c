/**
 * @file        main.c
 * @brief       GenericEmbeddableDoublyLinkedList: An efficient, embeddable doubly linked list library for C applications.
 * @author      Harshith Sunku
 * @date        12/22/2023
 * @version     1.0
 * @website     https://www.harshith.in/ | https://harshithsunku.in/
 * @repository  https://github.com/harshithsunku/GenericEmbeddableDoublyLinkedList
 *
 * @note        This file is part of GenericEmbeddableDoublyLinkedList, a library providing 
 *              an embeddable, generic doubly linked list implementation. It is designed to be 
 *              directly embedded into user-defined data structures, facilitating efficient and 
 *              flexible list operations.
 * @details     The implementation uses an intrusive approach, meaning the list nodes are part 
 *              of the structures that utilize the list, as opposed to being external standalone 
 *              structures. Further details about the implementation can be found in the README 
 *              or the official documentation at the above website/github.
 * 
 * GenericEmbeddableDoublyLinkedList is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GenericEmbeddableDoublyLinkedList is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GenericEmbeddableDoublyLinkedList. If not, see <https://www.gnu.org/licenses/>.
 *
 * @bugs        No known bugs at the time of writing.
 * @todo        Features or fixes planned for future versions.
 */

#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

// Define a structure that contains dll_t
typedef struct {
    int data;
    dll_t link;
} my_data_t;

int main() {
    // Create and initialize the list head
    dll_t list_head;
    dll_init(&list_head);

    // Create some test data
    my_data_t items[5];
    for (int i = 0; i < 5; ++i) {
        items[i].data = i;
        dll_init(&items[i].link);
        dll_push_back(&list_head, &items[i].link);
    }

    // Iterate over the list and print the data
    printf("List contents:\n");
    dll_t *iter;
    dll_traverse(&list_head, iter) {
        my_data_t *item = container_of(iter, my_data_t, link);
        printf("Data: %d\n", item->data);
    }

	my_data_t *temp;
	dll_traverse_entry(temp, &list_head, link, my_data_t){
		printf("Data: %d\n", temp->data);
	}

    return 0;
}

