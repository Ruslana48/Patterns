#include <iostream>
#include <string>

//Product class
class Computer{
    private:
        std::string cpu_;
        std::string memory_;
        std::string storage_;
    public:
        void setCPU(const std::string& cpu){
            cpu_=cpu;
        }
        void setMemory(const std::string& memory){
            memory_=memory;
        }
        void setStorage(const std::string& storage){
            storage_=storage;
        }
        void display(){
            std::cout << "CPU:" << cpu_ << std::endl;
            std::cout << "Memory:" << memory_ << std::endl;
            std::cout << "Storage:" << storage_ << std::endl;
        }
};

//Builder interface
class ComputerBuilder{
    public:
        virtual void buildCPU(const std::string& cpu) = 0;
        virtual void buildMemory(const std::string& memory) = 0;
        virtual void buildStorage(const std::string& storage) = 0;
        virtual Computer getResult() = 0;
};

//Concreate Builder
class DesktopComputerBuilder : public ComputerBuilder {
    private:
        Computer Computer_;
    public:
        DesktopComputerBuilder(){
            Computer_ = Computer();
        }
        void buildCPU(const std::string& cpu) override {
            Computer_.setCPU(cpu);
        }
        void buildMemory(const std::string& memory) override {
            Computer_.setMemory(memory);
        }
        void buildStorage(const std::string& storage) override {
            Computer_.setStorage(storage);
        }
        Computer getResult() override{
            return Computer_;
        }
};

//Director
class ComputerAssembler{
    public:
        Computer assembleComputer(ComputerBuilder& builder){
            builder.buildCPU("Intel i7");
            builder.buildMemory("16GB");
            builder.buildStorage("512GB SSD");
            return builder.getResult();
        }
};

int main(){
    DesktopComputerBuilder desktopComputerBuilder;
    ComputerAssembler assembler;
    Computer desktop = assembler.assembleComputer(desktopComputerBuilder);

    std::cout << "Desktop Computer Configuration: " << std::endl;
    desktop.display();
}