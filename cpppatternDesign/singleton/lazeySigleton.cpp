#include<iostream>
using namespace std;
class singleton
{
    private:
      singleton()
        {
            cout<<"this is lazy sigleton"<<endl;
        }
    public:
        static singleton *getInstance()
        {
            if(m_instance==NULL)
            {
                m_instance=new singleton;
            }
            return m_instance;
        }
        static void freeInstance()
        {
            if(m_instance!=nullptr)
            {
                delete m_instance;
                m_instance=nullptr;
                cout<<"free"<<endl;
            }
        }
    private:
        static singleton *m_instance;
        

};
singleton *singleton::m_instance=NULL;
void main2()
{
    singleton *s1=singleton::getInstance();
    singleton *s2=singleton::getInstance();
    if(s1==s2)
    {
        cout<<"是同一个对象"<<endl;
    }
    else
    {
        cout<<"不是同一个对象"<<endl;
    }
    singleton::freeInstance();
    return;
}
int main()
{
    main2();
    system("pause");

    return 0;
}