/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:12:45 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:12:46 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data data = {42, 'A'};
    Data* ptr = &data;

    uintptr_t serializedPtr = Serializer::serialize(ptr);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Serialized pointer: " << serializedPtr << std::endl;
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

    if (ptr == deserializedPtr) {
        std::cout << "Serialization and deserialization successful." << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed." << std::endl;
    }

    return 0;
}