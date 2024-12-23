#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    
    int max_width =0;
    int max_height =0;
    
    for (size_t i=0; i<sizes_rows; i++){
        //큰 값은 가로, 작은 값이 세로로 회전
        int width = sizes[i][0] > sizes[i][1]?sizes[i][0]:sizes[i][1];
        int height = sizes[i][0] > sizes[i][1]?sizes[i][1]:sizes[i][0];
        
        //최대 가로, 최대 세로
        if(width > max_width){
            max_width =width;
        }
        if(height > max_height){
            max_height=height;
        }
                
    }
    
    
    
    //지갑의 크기 
    return max_width * max_height;
}