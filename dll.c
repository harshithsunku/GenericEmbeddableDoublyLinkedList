/**
 * @file        dll.c
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

void dll_init(dll_t *node) {
    node->prev = node;
    node->next = node;
}

void dll_insert_after(dll_t *node, dll_t *new_node) {
    new_node->next = node->next;
    new_node->prev = node;
    node->next->prev = new_node;
    node->next = new_node;
}

void dll_insert_before(dll_t *node, dll_t *new_node) {
    new_node->prev = node->prev;
    new_node->next = node;
    node->prev->next = new_node;
    node->prev = new_node;
}

void dll_remove(dll_t *node) {
    dll_t *next_node = node->next;
    dll_t *prev_node = node->prev;
    prev_node->next = next_node;
    next_node->prev = prev_node;

    // Optionally reinitialize the removed node.
    dll_init(node);
}

void dll_push_front(dll_t *head, dll_t *new_node) {
    dll_insert_after(head, new_node);
}

void dll_push_back(dll_t *head, dll_t *new_node) {
    dll_insert_before(head, new_node);
}

dll_t *dll_next(const dll_t *node) {
    return node->next;
}

dll_t *dll_prev(const dll_t *node) {
    return node->prev;
}

