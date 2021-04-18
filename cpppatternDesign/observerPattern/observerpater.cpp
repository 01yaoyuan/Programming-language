#include<iostream>
#include<list>
#include<string>
using namespace std;
class secretary;
class playersObserver
{
    public:
        playersObserver(secretary *Secretary)
        {
            this->Secretary=Secretary;
        }
        void update(string action)
        {
            cout<<"action"<<action<<endl;
            cout<<"the boss is coming"<<endl;
        }
    private:
        secretary *Secretary;
};
class secretary
{
    public:
        secretary()
        {
            mList.clear();
        }
        void notice(string info)
        {
            for(list<playersObserver *>::iterator itr=mList.begin();itr!=mList.end();itr++)
            {
                (*itr)->update(info);
            }
        }
        void setPlayersObderver(playersObserver *o)
        {
            mList.push_back(o);
        }
    private:
    list<playersObserver *> mList;

};
int main()
{
    secretary *s=nullptr;
    playersObserver *pl1=nullptr;
    playersObserver *pl2=nullptr;
    s = new secretary;
    pl1=new playersObserver(s);
    pl2=new playersObserver(s);
    s->setPlayersObderver(pl1);
    s->setPlayersObderver(pl2);
    s->notice("the boss is coming");
    s->notice("the boss leaft");
    delete s;
    delete pl1;
    delete pl2;
    

    return 0;
}