#include<iostream>            //importing input output library
#include<torch/torch.h>        //importing pytorch libtorcj library.
#include<opencv2/opencv.hpp>     //importing OpenCV library .

int main(int argc ,char **argv){              //passing or providing command line arguments

    for(int i=1;i<argc;i++){                       //for loop to cycle through read images to the extend that is provided in command line.
        std::string img_path = argv[i];             //image path providing through command line
        cv::Mat img = cv::imread(img_path, 1);     //reading image by opencv
        cv::resize(img, img, cv::Size(224, 224), cv::INTER_CUBIC);  //Resizing the image to (height224 ,width 224)
        torch::Tensor img_tensor = torch::from_blob(img.data,{img.rows, img.cols, 3},torch::kByte);  //converting Opencv images to torch-tensors
        img_tensor = img_tensor.permute({2,0,1});      //Earlier it was 0,1,2 now it is 2,0,1 as channel comes first then width and height.
        std::cout << img_tensor << "\n";            //printing the torch tensors of respective images
        cv::imshow("Image",img);            //cv showing the image through its window

        int k =  cv::waitKey(3000);     //giving a 3 second time delay for showing the window of a CV image and move onto next image.
        if(k == 27){

            cv::destroyAllWindows();
            break;
        }

    }

    return 0;
    
}
