/* 友元关系 -- 在另一个类内部 访问 某个类 的 protected、private */

#include <iostream>
#include <string>

class Lovers
{
public:
      Lovers(std::string theName);
      ~Lovers();

      void Kiss(Lovers *lover);
      void Ask(Lovers *lover, std::string something);

protected:
      std::string name;

      friend class Others; // 友元关系
};

class Boyfriend : public Lovers
{
public:
      Boyfriend(std::string theName);
};

class Girlfriend : public Lovers
{
public:
      Girlfriend(std::string theName);
};

class Others
{
public:
      Others(std::string theName);
      // ~Others();

      void Kiss(Lovers *lover);

protected:
      std::string name;
};

Lovers::Lovers(std::string theName)
{
      name = theName;
}

Lovers::~Lovers()
{
      ;
}

void Lovers::Kiss(Lovers *lover)
{
      std::cout << name << " kiss " << lover->name << std::endl;
}

void Lovers::Ask(Lovers *lover, std::string something)
{
      std::cout << lover->name << " help " << name << something << std::endl;
}

Boyfriend::Boyfriend(std::string theName) : Lovers(theName)
{
}

Girlfriend::Girlfriend(std::string theName) : Lovers(theName)
{
}

Others::Others(std::string theName)
{
      name = theName;
}

void Others::Kiss(Lovers *lover)
{
      std::cout << name
                << "\033[5;31;40m"
                << " kiss "
                << "\033[0m"
                << lover->name
                << std::endl;
}

int main(int argc, char const *argv[])
{
      Boyfriend boyfriend("阿杰");
      Girlfriend girlfriend("小月");

      Others others("黄毛");

      boyfriend.Kiss(&girlfriend);
      boyfriend.Ask(&girlfriend, "口");

      std::cout << "\n暴露调教...\n ";
      others.Kiss(&girlfriend);

      return 0;
}
