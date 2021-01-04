#include<iostream>
#include<torch/torch.h>

int main(){
   
    torch::Tensor tensor=torch::eye({4});
    torch::Tensor xRandom=torch::randn({2,4});
    std::cout<<tensor<<"\n";
    std::cout<<xRandom<<"\n";
}

