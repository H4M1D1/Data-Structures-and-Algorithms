#include "polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial(int A[], int size) {

    size_ = size;

    int index = 0;

    while(index != size){       // go through loop and add values from array to back of linked list

        coefficients.insert_back(A[index]);

        index ++;       // increment index
    }
}

Polynomial* Polynomial::add(Polynomial* rhs) {

    int maxSize = 0;
    int minSize = 0;

    if(rhs->coefficients.size() < coefficients.size()){     

        maxSize = size_;
        minSize = rhs->size_;
    }

    else{               

        maxSize = rhs->size_;
        minSize = size_;

    }

    int newArray[maxSize];      

    for(int i = 0; i < minSize; i ++){          

        newArray[i] = coefficients.select(i) + rhs->coefficients.select(i);

    }

    if(rhs->size_ == maxSize){              

        for(int i = minSize; i < maxSize; i++){

            newArray[i] = coefficients.select(i);
        }
    }

    else{                                   

        for(int i = minSize; i < maxSize; i++){

            newArray[i] = rhs->coefficients.select(i);
        }
    }

    Polynomial *newPloynomial = new Polynomial(newArray, maxSize); 

    return newPloynomial;       

}

Polynomial* Polynomial::sub(Polynomial* rhs) {

    int maxSize = 0;
    int minSize = 0;

    if(rhs->coefficients.size() < coefficients.size()){     

        maxSize = size_;
        minSize = rhs->size_;

    }
    
    else{

        maxSize = rhs->size_;
        minSize = size_;
    }

    int newArray[maxSize];          

    for(int i = 0; i < minSize; i ++){          

        newArray[i] = coefficients.select(i) - rhs->coefficients.select(i);
    }

    if(rhs->size_ == maxSize){          

        for(int i = minSize; i < maxSize; i++){

            newArray[i] = rhs->coefficients.select(i);
        }
    }
    else{                              

        for(int i = minSize; i < maxSize; i++){

            newArray[i] = coefficients.select(i);
        }
    }
    Polynomial *newPloynomial = new Polynomial(newArray, maxSize);      

    return newPloynomial;       
}

Polynomial* Polynomial::mul(Polynomial* rhs) {

    int maxSize = rhs->coefficients.size() + coefficients.size() -1;
    int newArray[maxSize];

    for(int i = 0; i < maxSize; i ++){

        newArray[i] = 0;                
    }

    for(int i =0; i < coefficients.size() ; i++ ){      
        
        for(int j = 0; j < rhs->coefficients.size(); j ++){
            
            newArray[i+j] +=  coefficients.select(i) * rhs->coefficients.select(j);     
        }
    }

    Polynomial *newPolynomial = new Polynomial(newArray, maxSize);     

    return newPolynomial;      
}
void Polynomial::print() {

 int count = size_ -1;
    
    for(int index = size_ -1; index>=0; index--){

        if(coefficients.select(index) > 0) {
           
            cout << coefficients.select(index) << "x^" << index;       
            count = index-1;

            break;      
        }
        else if(coefficients.select(index) < 0){

            cout<< "(" << coefficients.select(index)<<")" <<"x^" <<index;   
            count = index-1;

            break;     
        }
    }
    
    for(count-1; count >= 0; count--){

        if (coefficients.select(count) > 0){        

            cout<< " + " << coefficients.select(count) << "x^" << count;     

        }

        else if(coefficients.select(count) < 0){        

            cout << " + " << "(" << coefficients.select(count)<<")" <<"x^" <<count;     
        }
    }
    
    cout<<endl;
}
