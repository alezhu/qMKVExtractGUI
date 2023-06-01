#include <exception>

int main(int argc, char *argv[])
{
        try
        {
        }
        catch (const std::exception &e)
        {
                //        e.what()
                return 1;
        }
}
