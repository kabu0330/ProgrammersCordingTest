#include <iostream>
#include <vector>

class AActor
{
public:
    AActor() {};

    // virtual void Test() {};

};

class APlayer : public AActor
{
public:
    APlayer() {};

    virtual void Test() {};
};

class AKnight : public APlayer
{
public:
    AKnight() {};
};


int main()
{
    //std::vector<int> VecInt;
    //std::vector<float> VecFloat;

    //VecInt = static_cast<std::vector<int>>(VecFloat);
    //APlayer* Player = GetWorld()->SpawnActor<APlayer>();

    AActor* Actor = new APlayer;
    APlayer* Player = dynamic_cast<APlayer*>(Actor);
    // 상속만 받아서는 다이나믹 캐스팅이 안된다?
    // 반드시 virtual로 만들어야 한다.

    //APlayer* NewPlayer = new APlayer;
    //NewPlayer 

    if (nullptr != Player)
    {
        int a = 0;
    }

}

