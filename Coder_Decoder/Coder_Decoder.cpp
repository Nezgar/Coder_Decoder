#include <iostream>
#include <cstdlib>
#include <vector>
/* ========================================= =========================================
                Для смены ключа, необходимо поменять значения в членах-данных   m_key и m_ckey
   ========================================= =========================================*/

class Enigma {
public:
    std::string m_phrase = "";
    std::vector<int> m_position;
    std::string m_shakePhrase = "";
    std::string m_returnPhrase = "";
    int m_key{ 4541 };                  //номер ключа
    char m_ckey{'A'};                   //буква ключа
    void coder(std::string &m_phrase, std::vector<int> &m_position, std::string &m_shakePhrase);
    
    void enterPhrase();
    void decoder();
    void intro();
    void coderResult(std::string &m_shakePhrase);
    void decoderResult(std::string& m_returnPhrase);
    void onlyDecoder(int key= 4541, char ckey='A');
    void showKey();
};

//Показывает ключ
void Enigma::showKey() {
    std::cout << "Ключ - "<<m_key<<m_ckey<<"\n\n";
    
};
// Показывает вступление
void Enigma::intro() {
    std::cout << "Вас приветсвует \"Шифровальная машина \"Энигма\"\".\n";
    std::cout << "Внимание, вместо пробелов необходимо использовать знак \"_\".\n";
    std::cout << "Выбор пунктов в меню с помощью цифр.\n\n\n";
}
//Выводит результат шифратора
void Enigma::coderResult(std::string &m_shakePhrase) {
    std::cout << "Фраза после шифровки - \"" << m_shakePhrase << "\"" <<"\n";

}
//Выводит результат дешифратора
void Enigma::decoderResult(std::string& m_returnPhrase) {
    std::cout << "Фраза после расшифровки - \" " << m_returnPhrase << " \"" << "\n";

}
//Просит ввести фразу для шифровки/ дешифровки
void Enigma::enterPhrase() {
    
    std::cout << "Введите фразу(вместо пробелов использовать знак \"_\") - ";
    std::cin >> m_phrase;
    std::cout << "\n";
    }

//Шифратор
void Enigma::coder(std::string &m_phrase, std::vector<int> &m_position, std::string &m_shakePhrase) {
    srand(m_key);
    std::vector<int>::iterator myIterator;
    int c;
    c = (rand() % m_phrase.size()) + 1;
    m_position.push_back(c);
    
    int  d{ 0 } ;
    char l{ 0 };
    bool f = true;
    /* Проходя по массиву введенного слова, создается новый динамический массив в который записываются случайно
    * сгенерированные числа.*/
    while (d <= m_phrase.size()-2) {
        for (int i = 0; i <= m_phrase.size()-2; i++) {
            f = true;
            while (f == true) {
                c = (rand() % m_phrase.size()) + 1;
                
                for (myIterator = m_position.begin();myIterator != m_position.end();++myIterator) {
                    if (*myIterator == c) {
                        f = true;
                        break;
                    }
                    else if (*myIterator != c) {
                        f = false;
                    }
                }

                if (f == false) {
                    l = c;
                    d++;
                    m_position.push_back(l);
                    

                }
            }
        }
    }

    //Меняет буквы местами(наверное лучше сделать отдельную функцию)
    for (int i = 0; i <= m_phrase.size()-1; i++) {
        m_shakePhrase += m_phrase[m_position[i]-1];
      
    }
    //Шифрует буквы (наверное лучше сделать отдельную функцию)
    for (int i = 0; i <= m_shakePhrase.size() - 1; i++) {
        m_shakePhrase[i] = m_shakePhrase[i] ^ m_ckey;
    }
}

//Дешифратор(работает только с шифратором)
void Enigma::decoder() {
    std::vector<int>::iterator myIterator;
    char x = ' ';
    

    for (int i = 0; i <= m_shakePhrase.size()-1; i++) {
        m_shakePhrase[i] = m_shakePhrase[i] ^ 'A';
    }
    std::cout <<  "\n";
   



    for (int i = 0; i <= m_phrase.size()-1 ; i++) {
        for (int j = 0; j <= m_phrase.size()-1; j++) {
            if (m_position[j] == (i+1)) {
                x= m_shakePhrase[j];
                break;
            }
        }
        m_returnPhrase += x;
        
        
    }

}
//ТОЛЬКО дешифрует
void Enigma::onlyDecoder(int key,char ckey) {
    srand(key);
    std::vector<int>::iterator myIterator;
    int c;
    c = (rand() % m_phrase.size()) + 1;
    m_position.push_back(c);
    
    /*Благодаря ключу создается массив чисел ,происходит расшифровка ,далее в string фразу записываются буквы 
    стоящие на значениях записанных в массиве чисел. */

    int  d{ 0 };
    char l{ 0 };
    bool f = true;
    while (d <= m_phrase.size() - 2) {
        for (int i = 0; i <= m_phrase.size() - 2; i++) {
            f = true;
            while (f == true) {
                c = (rand() % m_phrase.size()) + 1;
                

                for (myIterator = m_position.begin(); myIterator != m_position.end(); ++myIterator) {
                    if (*myIterator == c) {
                        f = true;
                        break;
                    }
                    else if (*myIterator != c) {
                        f = false;
                    }
                }

                if (f == false) {
                    l = c;
                    d++;
                    m_position.push_back(l);


                }
            }
        }
    }
    char x = ' ';

    for (int i = 0; i <= m_phrase.size() - 1; i++) {
        m_phrase[i] = m_phrase[i] ^ ckey;
    }
    std::cout << "\n";
    
    for (int i = 0; i <= m_phrase.size() - 1; i++) {
        for (int j = 0; j <= m_phrase.size() - 1; j++) {
            if (m_position[j] == (i + 1)) {
                x =m_phrase[j];
                break;
            }
        }
        m_returnPhrase += x;
       
    }
}


int main()
{
    system("chcp 1251 > nul");
     
    int choose{ 0 }, choose2{0};
     bool start = true;
     int key = { 0 };
     char ckey = ' ';
     Enigma phrase;
     phrase.intro();
     std::cout << "Зашифровать фразу - 1.\n";
     std::cout << "Расшифровать зашифрованную фразу - 2 (только при первом запуске программы)\n";
     std::cout << "Выход из программы - 0\n";
    
     
     while (start) {
         std::cout << "\n";
         
         std::cin >> choose;
         if (choose == 1) {
             phrase.enterPhrase();
             phrase.coder(phrase.m_phrase, phrase.m_position, phrase.m_shakePhrase);
             phrase.coderResult(phrase.m_shakePhrase);
             phrase.showKey();
             std::cout << "Если вы хотите дешифровать эту фразу, нажмите 2.\n";
             std::cout << "Для выхода из программы нажмите 0\n";
             std::cin >> choose2;
             if (choose2 == 2) {
                 
                 phrase.decoder();
                 phrase.decoderResult(phrase.m_returnPhrase);
                 start = false;
             }
             else if (choose2 == 0) {
                 start = false;
             }
             
         }
         else if (choose == 2) {
             phrase.enterPhrase();
             std::cout << "Как пример можно использовать слово -) \".-$\" \n";
             std::cout << "Введите ключ.\n";
             std::cout << "Число- ";
             std::cin >> key;
             std::cout << "\n";
             std::cout << "Буквы(латинские)- ";
             std::cin >> ckey;
             std::cout << "\n";
             phrase.onlyDecoder(key, ckey);
             phrase.decoderResult(phrase.m_returnPhrase);
             start = false;
         }
         else if (choose == 0) {
             start = false;
         }
         else {
             std::cout << "\aВ этой шифровальной машине данная функция отсутствует.\n";
         }
     }
    
      return 0;
}
