

#include <cstdlib>
#include <memory>
#include <vector>
#include <iostream>
#include <cassert>

struct BasePackage
{
   int id;

   BasePackage(int id1) : id(id1) 
   {
       std::cout << "create package with id = " << id << std::endl;
   }


   virtual ~BasePackage() 
   {
       std::cout << "destruct package with id = " << id << std::endl;
   }

};

typedef std::shared_ptr<BasePackage> BasePackagePtr;

struct ACore
{
   int a1;
   int a2;
};

struct A : public BasePackage
{
   ACore core;

   A(int x1, int x2) : BasePackage(0)
   {
      core.a1 = x1;
      core.a2 = x2;
      std::cout << "create A object (" << id << "," << core.a1 << "," << core.a2 << ")" << std::endl;
   }

   ~A()
   {
      std::cout << "destroy A object (" << id << "," << core.a1 << "," << core.a2 << ")" << std::endl;
   }

};

typedef std::shared_ptr<A> APtr;

struct B : public BasePackage
{
   int b1;
   int b2;
   int b3;

   B() : BasePackage(1) , b1(0), b2(0), b3(0) {}

   B(int x1, int x2, int x3) : BasePackage(1) , b1(x1), b2(x2), b3(x3) {}
};

typedef std::shared_ptr<B> BPtr;

typedef std::vector<BasePackagePtr> PackageSequence;

int main()
{
    {
        PackageSequence s;

        s.push_back(BasePackagePtr(new A(1,3)));
        s.push_back(BPtr(new B));
        s.push_back(BPtr(new B));
        s.push_back(BasePackagePtr(new A(2,3)));
        
        auto p = s[3];

        auto a = std::static_pointer_cast<A>(p);
        assert(a->id == 0);

        std::cout << a->id << "\t" << a->core.a1 << "\t" << a->core.a2 << std::endl;

        auto b = std::dynamic_pointer_cast<B>(p);
        assert(!b);

        for(auto i = s.begin(); i != s.end(); ++i)
           std::cout << (*i)->id << std::endl;
      
    }

    std::cout << "before exit " << std::endl;


    return EXIT_SUCCESS;
};
