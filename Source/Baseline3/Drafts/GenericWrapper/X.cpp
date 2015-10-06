
#include <memory>
#include <iostream>

struct BasePacket
{
    int id;

    BasePacket(int idvalue) : id(idvalue) {}

};

typedef std::shared_ptr<BasePacket> BasePacketPtr;

struct A
{
  int a;
};

int packet_id(const A* ) { return 1; }


struct B
{
  int b1;
  int b2;
};

int packet_id(const B*) { return 2; }

template<typename T>
struct Generic : public BasePacket
{
    T core;

    Generic() : BasePacket(packet_id(&core)), core() {}
};

int main()
{
   
   Generic<A> a;
   std::cout << "a.id = " << a.id << std::endl;

   Generic<B> b;
   std::cout << "b.id = " << b.id << std::endl;

   BasePacketPtr ap = std::make_shared<Generic<A>>();
   std::cout << "ap->id = " << ap->id << std::endl;

   return EXIT_SUCCESS;
}

