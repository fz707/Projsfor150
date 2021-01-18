#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif

//function declarations
unsigned int add_checksum( unsigned int n );
void add_checksum( unsigned int array [], std::size_t capacity );
bool verify_checksum( unsigned int n);
unsigned int remove_checksum ( unsigned int n);
void remove_checksum( unsigned int array [], std::size_t capacity );
#ifndef MARMOSET_TESTING
int main() {
   /* std::cout << add_checksum(12345678) << std::endl;
    
    unsigned int value_to_protect{21352411};
   unsigned int protected_value = add_checksum(value_to_protect);

    std::cout << "The value " << value_to_protect
              << " with the checksum added is " << protected_value
              << "." << std::endl;
    std::cout << add_checksum(1) << std::endl;

   if (verify_checksum(1230)){
        std::cout << "The checksum is valid." << std::endl;
    }
    else
    {
        std::cout << "The checksum is invalid." << std::endl;
    }

    std::size_t const qty_values {3};
    unsigned int value_series[qty_values] {20201122, 20209913, 20224012};

    add_checksum(value_series, qty_values);
    

    std::cout << "Series with checksums added: ";
    for (std::size_t series_index {0}; series_index < qty_values; series_index++)
    {
        std::cout << value_series[series_index] << " ";
    }
    std::cout << std::endl;
    
    std::cout << remove_checksum(123456780) << std::endl;

     return 0; */
}
#endif

unsigned int add_checksum( unsigned int n ){
    if (n>99999999){
        
        return UINT_MAX;
    }
   
    int count{};
    int arrayCount{};
    int temp{};
    int sum{};
    int checksumadded{};
    temp=n;
    if (n==0){
        temp=0;
        count=0;
        arrayCount=0;
    }
    while (temp != 0)
    {
        temp=temp/10;
        count+=1;
    }
    if (count>8){
        return UINT_MAX;
    }
   
    if (n==0){
        arrayCount=0;
    }
    else{
    arrayCount=count-1;
    }
    int dataset[count];
    int alternateset[count];
    for (int i=arrayCount; i>=0; i--){
        dataset[i] = n % 10;
        n /= 10;
        dataset[count]=0;
        alternateset[i]=dataset[i];
    }

       
    
    for (int k=0; k<=count; ++k){
        
        
    }
    
    for ( int k=arrayCount; k>=0; k-=2){
        dataset[k] *= 2;
        if (dataset[k]>=10){
            dataset[k]=(dataset[k] %10) + (dataset[k]/10);
        }
    }
    for (int k=0; k<=count; ++k){
        sum += dataset[k];
       
    }
    sum=(sum*9) %10;
    
  
    alternateset[count]=sum;
    for (int k=0; k<=count; ++k){
        checksumadded*=10;
        checksumadded+= alternateset[k];
    }
    return checksumadded;
}
bool verify_checksum( unsigned int n){
    if (n>999999999){
        return false;
    }
    int temp2{};
    temp2=n/10;
    if (n==add_checksum(temp2)){
        return true;
    }
    else{
        return false;
    }
}
unsigned int remove_checksum( unsigned int n){
    if(n>999999999){
       return UINT_MAX;
   }
    if (verify_checksum(n)==true){
        return n/10;
    }
    else{
        return UINT_MAX;
    }
}
void add_checksum( unsigned int array[], std::size_t capacity ){
for ( std::size_t array_index{0}; array_index<capacity; array_index++){
    
    array[array_index]= add_checksum(array[array_index]);
}
}
void remove_checksum( unsigned int array[], std::size_t capacity ){
for ( std::size_t array_index{0}; array_index<capacity; array_index++){
    
    array[array_index]= remove_checksum(array[array_index]);
}
}



