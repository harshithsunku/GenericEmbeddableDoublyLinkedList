/**
 * @file        dll.h
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

#ifndef DLL_H
#define DLL_H

#include <stddef.h>

// Define the embeddable doubly linked list node structure
typedef struct dll {
    struct dll *prev;
    struct dll *next;
} dll_t;

// Initialize a DLL node
void dll_init(dll_t *node);

// Insert a new node after a given node
void dll_insert_after(dll_t *node, dll_t *new_node);

// Insert a new node before a given node
void dll_insert_before(dll_t *node, dll_t *new_node);

// Remove a node from the list
void dll_remove(dll_t *node);

// Push a new node at the front of the list
void dll_push_front(dll_t *head, dll_t *new_node);

// Push a new node at the end of the list
void dll_push_back(dll_t *head, dll_t *new_node);

// Get the next node in the list
dll_t *dll_next(const dll_t *node);

// Get the previous node in the list
dll_t *dll_prev(const dll_t *node);

// Iterate over the dll
#define dll_traverse(head, iter) \
    for ((iter) = (head)->next; (iter) != (head); (iter) = (iter)->next)

// Get the pointer to the user structure where dll is used
#define container_of(ptr, type, member) ({            \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type, member) );})

// Travers user DS which uses dll
#define dll_traverse_entry(pos, head, member, type) \
    for (pos = container_of((head)->next, type, member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, type, member))

#define DLL_TO_STRUCT(fn_name, structure_name, field_name)                        \
    static inline structure_name * fn_name(dll_t *dllptr){                   \
        return (structure_name *)((char *)(dllptr) - (char *)&(((structure_name *)0)->field_name)); \
    }

#endif // DLL_H

