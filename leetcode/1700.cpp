// Runtime 0 ms Beats 100%
// Memory 8.8 MB Beats 69.33%

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size = students.size();
        queue<int> choices;
        int i=0;
        while(i<size){
            choices.push(students[i]);
            i++;
        }
        int repeats=0;
        i=0;
        while(choices.size() && choices.size() > repeats){
            if(choices.front() == sandwiches[i]){
                i++;
                choices.pop();
                repeats=0;
            } else{
                repeats++;
                int temp = choices.front();
                choices.pop();
                choices.push(temp);
            }
        }
        return choices.size();
    }
};


// Runtime 3 ms Beats 69.90%
// Memory 8.8 MB Beats 69.33%

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size = students.size();
        queue<int> stds;
        for(int i=0;i<size;i++){
            stds.push(students[i]); // push student choices to queue
        }
        int temp=0; int i=0;
        while(temp < stds.size() && stds.size()){ // stop loop if no elements in queue and if temp equal or bigger than queue size than no matches left
            if(stds.front() == sandwiches[i]){ // if equal remove student from queue
                i++;
                stds.pop();
                temp=0;
            }else{
                temp++;
                int stds_choice = stds.front(); // add student choice to the end of queue
                stds.pop();
                stds.push(stds_choice);
            }
        }
        return stds.size();
    }
};
