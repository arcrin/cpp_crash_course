//
// Created by wbai on 11/25/2021.
//

/*
 * Instead of writing your own RAII objects, you can use smart pointers to handle resource management.
 *
 * Smart pointers are class templates that behave like pointers and implement RAII for dynamic objects.
 *
 */

/*
 * Smart Pointer Ownership
 *
 * Smart pointer has ownership model. When a smart pointer owns a dynamically allocated object, it manages
 * the destruction of the object.
 *
 * the choice of smart pointer depends on the ownership requirement
 */