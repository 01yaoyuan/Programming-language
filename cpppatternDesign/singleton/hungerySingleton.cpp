#include<iostream>
using namespace std;
class singleton
{
    public:
        static singleton *getInstance()
        {
            return m_instance;
        }
        static void freeInstance()
        {
            if(!m_instance)
            {
                delete m_instance;
                m_instance=nullptr;
                
            }
        }
    private:
        static singleton *m_instance;
        singleton()
        {
            cout<<"this is hungery"<<endl;
        }



};
singleton *singleton::m_instance=new singleton;
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