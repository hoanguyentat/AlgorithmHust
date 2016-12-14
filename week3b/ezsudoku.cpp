/**
    * Đọc lần đầu để được số test_cases
    * Đọc từng số một lưu vào mảng hai chiều 8*8, sao cho trong một khối 4*4 các số từ 1->8 xuất hiện k quá 2 lần
    * Kiểm tra ma trận đầu vào giá trị tại ô i,j xem đã tồn tại giá trị đó trong hàng, 
        * trong cột, nó có xuất hiện quá 2 lần tại ma trận con 4x4 chưa?
        * nếu một trong các điều kiện xuât hiện thì in ra màn hình "No"
    * Nếu không xuất hiện thì in ra "YES"  và ma trận tương ứng
    * Tại một ô tọa độ i, j:
        * Đã được điền (có giá trị khác 0) thì hãy chuyển sang ô tiếp theo i, j+1 hoặc i+1, 0 (trường hợp xuống dòng)
        *  Chưa được điền thử giá trị k (trong khoảng từ 1-8) kiểm tra k xem đã tồn tại trong hàng, cột, hoặc hình vuông 4*4  
            * quá hai lần chưa nếu chưa thì set giá trị tại ô i,j là k và chuyển đến ô tiếp theo i, j+1 hoặc i+1, 0.
            * nếu i, j có thể đi qua ô tọa độ 7,7 thì tồn tại solution và in ra ma trận.
            * Sử dụng 1 cờ flag để thoát khỏi hàm backtrack khi đã tìm được solution.
    * Độ phức tạp thuật toán O(nlogn)
*/

#include <iostream>

using namespace std;
int matrix[10][10];
int flag;

//Kiểm tra xem mỗi block xem mỗi số đã quá hai lần chưa
int blocks(int x, int y)
{
    int startx = x/4;
    int starty = y/4; 
    int end_x = startx*4 + 4; 
    int end_y = starty*4 + 4;

    int flag_block[9];
    for(int i=0; i<9; i++) 
        flag_block[i] = 0;

    for(int i= startx*4; i < end_x; i++)
        for(int j=starty*4; j< end_y; j++)
        {
            if(matrix[i][j] == 0) continue;
            flag_block[matrix[i][j]]++; 
            if(flag_block[matrix[i][j]]>2)
                return 1;
        }
        return 0;
}
//Kiểm tra xem hàng, cột xem đã tồn tại số k chưa
int rows_cols(int x, int y)
{
    int flag_row[10];
    int flag_col[10];
    for(int i=0; i<9; i++)
        flag_row[i] = flag_col[i] =0;
    // Kiểm tra hàng
    for(int i=0; i<8; i++){
        if(matrix[x][i]==0)
            continue;
        flag_row[matrix[x][i]]++;
        if(flag_row[matrix[x][i]]>1)
            return 1;
    }
    // kiểm tra cột
    for(int i=0; i<8; i++){
        if(matrix[i][y]==0)
            continue;
        f_col[matrix[i][y]]++;
        if(f_col[matrix[i][y]]>1)
            return 1;
    }
    return 0;
}
int check_full_row_col()
{
    for(int i=0; i<8; i++)
        if(rows_cols(i,i) == 1) return 1;
    return 0;
}

// Tìm solution
void result(int x, int y)
{
    if(x>=8)
    {
        flag = 1;
        return;
    }
    if(matrix[x][y]!=0)
    {
        if(y<7)result(x, y+1);
        else result(x+1, 0);
    }
    else
    {
        for(int i = 1; i <= 8; i++)
        {
            matrix[x][y] = i;// thử giá trị i vào tọa độ x, y
            if(!rows_cols(x, y) && !blocks(x, y))
            {
                if(y<7) result(x, y+1); // đệ quy
                else result(x+1, 0);                
            }
            if(flag == 1) return;
            matrix[x][y] = 0;
        }
    }
}

int main()
{
    int test_case;
    scanf("%d", &test_case);
    for(int test = 1; test <= test_case; test++)
    {
        int startx = -1, starty = -1;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
            {
                scanf("%d", &matrix[i][j]);
                if(matrix[i][j] == 0 && startx == -1)
                {
                    startx = i;
                    starty = j;
                }
            }
            flag = 0;
            //Kiểm tra xem nếu thỏa mãn các điều kiện đề bài thì tìm solutions!
            if(!blocks(0,0) && !blocks(0,4 )&& !blocks(4,0) && !blocks (4,4) && !check_full_row_col())
            {
                result(startx, starty);
                if(flag)
                {
                    printf("Test case #%d: YES\n", test);
                    for(int i=0; i<8; i++)
                    {
                        for(int j=0; j<8; j++)
                            printf("%d ", matrix[i][j]);
                        printf("\n");
                    }
                }
                else printf("Test case #%d: NO\n", test);
            }
            else printf("Test case #%d: NO\n", test);
    }
    return 0;
}