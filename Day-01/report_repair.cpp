#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

//Day 01, Part 2
int productOfThreeWithGivenSum(std::vector<int>& entries, int target){
  int n = entries.size();
  std::sort(entries.begin(), entries.end());

  for(int i=0; i<n-2; i++){
    if(i>0 && entries[i-1] == entries[i]){
      continue;
    }

    int left = i+1;
    int right = n-1;
    while(left<right){
      int sum = entries[i] + entries[left] + entries[right];
      if(sum > target)
        right--;
      else if(sum < target)
        left++;
      else{
        int multiply = entries[i] * entries[left] * entries[right];
        std::cout << multiply << std::endl;
        return multiply;
      }
    }
  }
  throw std::runtime_error("Can't find 3 entries with the given sum!!!");

}

//Day 02, Part 1
int productOfTwoWithGivenSum(std::vector<int>& entries,int target){
  std::unordered_set<int> my_set;
  
  for(const auto& e:entries){
    my_set.insert(e);
  }
  
  for(const auto& e:entries){
    const int req_sum = target - e;
    if(my_set.find(req_sum) != my_set.end()){
      std::cout << e*req_sum << std::endl;
      return e * req_sum;
    }
    //my_set.insert(e);
  }
  throw std::runtime_error("Can't find two entries with the given sum.");
}

int main(){

  //Input data
  std::fstream input_file("input.txt");
  std::vector<int> entries;
  std::string line_buffer;
  while(std::getline(input_file,line_buffer)){
    const int entry = std::stoi(line_buffer);
    entries.emplace_back(entry);
  }
  
  //Given initial test set
  //std::vector<int> entries{1721,979,366,299,675,1456};

  int target = 2020;
  
  //Part 1
  int res_1 = productOfTwoWithGivenSum(entries,target);
  std::cout << "Product of Two Sum: " << res_1 << "\n";

  //Part 2
  int res_2 = productOfThreeWithGivenSum(entries,target);
  std::cout << "Product of Three Sum: " << res_2 << "\n";

  return 0;
}
