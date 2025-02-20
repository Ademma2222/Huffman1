#include "HuffmanEncoder.h"
#include "HuffmanDecoder.h"
#include "HuffmanTree.h"
#include <iostream>

int main() {
      {
    std::string inputText = "/Users/bulatmudarisov/Documents/Xcode Projects/Haffman/Haffman/input.txt";
    std::string encodedText = "/Users/bulatmudarisov/Documents/Xcode Projects/Haffman/Haffman/compressed.huff";
    std::string decodedText = "/Users/bulatmudarisov/Documents/Xcode Projects/Haffman/Haffman/output.txt";
    HuffmanTree treeText;       // Создаём дерево Хаффмана для текстовых данных
    HuffmanEncoder encoderText; // Создаём объект для кодирования
    HuffmanDecoder decoderText; // Создаём объект для декодирования
    
    encoderText.encodeFile(inputText, encodedText, treeText); // Кодируем файл
    decoderText.decodeFile(encodedText, decodedText, treeText); // Декодируем файл
    std::cout << "Текстовый файл успешно сжат и декодирован!" << std::endl;
      }
    
        // Кодирование и декодирование изображения (бинарного файла)
      {
    std::string inputImage = "/Users/bulatmudarisov/Documents/Xcode Projects/Haffman/Haffman/test.png";
    std::string encodedImage = "/Users/bulatmudarisov/Documents/Xcode Projects/Haffman/Haffman/compressed_image.huff";
    std::string decodedImage = "/Users/bulatmudarisov/Documents/Xcode Projects/Haffman/Haffman/decoded_test.png";
    
    HuffmanTree treeImage;       // Создаём дерево Хаффмана для изображения
    HuffmanEncoder encoderImage; // Создаём объект для кодирования
    HuffmanDecoder decoderImage; // Создаём объект для декодирования
    
    encoderImage.encodeFile(inputImage, encodedImage, treeImage); // Кодируем изображение
    decoderImage.decodeFile(encodedImage, decodedImage, treeImage); // Декодируем изображение
    
    std::cout << "Изображение успешно сжато и декодировано!" << std::endl;
      }
    return 0;
}
