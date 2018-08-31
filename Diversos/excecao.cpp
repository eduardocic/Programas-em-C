// ************************************************
//  Tratamento de Exceções
//  Excecoes2.cpp
// ************************************************
#include <iostream>
#include <string>

using namespace std;

class TrataDivZero
{
      public:
            TrataDivZero(int n);           
            void Msg();
      private:
            int NLinha;
};


TrataDivZero::TrataDivZero(int n)
{
     this->NLinha = n;
}     


void TrataDivZero::Msg()
{
      cout << "Tratador de erro foi chamado ..." << endl;
      cout << "Erro na linha: " << this->NLinha << endl;    
}     


int main()
{
    
     int n, m;
     char a = 'B';

     cout << "Numerador: ";
     cin >> n;
     cout << "Denominador: ";
     cin >> m;
   
     try // inicio do bloco TRY
     {
       
        if (m == 0)
        { 
             // Lança a exceção, criando um objeto da 
             // classe TrataDivZero e passando o 
             // número da linha onde o erro ocorreu
             throw (TrataDivZero(__LINE__)); 

             //
             // dentro deste bloco nada é executado 
             // após o throw. 
        }
        if(m == 10){
            throw 200;
        }
        if(m == 20){
            string temp = "Nr. negativo."; 
            throw (string(temp));
        }
        if(m == 30)
        {
            throw 3.14;
        }


        cout << "Divisão: "  << (double)n/m << endl;
     }
     


     catch (TrataDivZero T){                     
          T.Msg();
     }

     catch (int x){
        cout << "Imprime o inteiro: " << x << endl;
    
     }
     

     catch (double x){
        cout << "Imprime um double: " << x << endl;
     }

     catch (string S){
        cout << "Imprime uma string: " << S << endl;
     }
     
     catch (...){
        cout << "Default" << endl;
     }

     cout << "Fim..." << endl;
     return 0;
}