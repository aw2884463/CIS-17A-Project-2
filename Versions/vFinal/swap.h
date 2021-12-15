/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   swap.h
 * Author: Austin
 *
 * Created on December 10, 2021, 12:05 PM
 */

#ifndef SWAP_H
#define SWAP_H

template <class T>
void change(T& a,T& b)
{
     T temp;
     temp=a;
     a=b;
     b=temp;
}


#endif /* SWAP_H */

