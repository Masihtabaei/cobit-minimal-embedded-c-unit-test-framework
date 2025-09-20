# cobit - A Minimal Embedded C Unit Test Framework

> [!NOTE]  
> This project was completed as part of the **Applied Microcomputer Technology** course during the **Summer Term 2023** of our undergraduate studies, offered by [Prof. Dr. Peter Raab](https://www.oth-aw.de/hochschule/ueber-uns/personen/raab-peter/) at [Coburg University](https://www.hs-coburg.de/en/). It was originally developed outside of GitHub and later partially migrated here, so some elements may be missing.

> [!IMPORTANT]  
> This project is licensed under the [MIT License](https://masihtabaei.dev/licenses/mit).

## Technologies Used

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Static Badge](https://img.shields.io/badge/arm_Keil_%C2%B5Vision_IDE-green?style=for-the-badge)
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)

## General Information

Here you will find a minimal unit test framework for C to use in your embedded project.

I created this framework over the night in summer of 2023 for testing my embedded programs
written in C for Nucleo-Board (with an Arm Cortex M4 based processor / STM32G474).
It uses the sprintf and a two dimensional array as a buffer to display the test results.
I called it **cobit**. **cobit** is a partial blend (**Coburg** \[name of a small city located in Bavaria in Southern Germany\] + **Unit** \[for unit tests\])
Feel free to extend/adjust this project so that it meets your goals.

## Usage/Example

There is a file (example.c) which shows you how to use this minimal test framework.
You can not execute that file (becaue there are other header files that you have to add to your project)
but the purpose of this file should be giving you ideas how can you use this framework your personal projects.


