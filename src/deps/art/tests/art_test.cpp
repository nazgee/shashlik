#include <runtime.h>

using namespace art;

int main(int argc, char** argv)
{
    if(Runtime::Current()) {
        std::cerr << "Test";
    }
    return 0;
}
