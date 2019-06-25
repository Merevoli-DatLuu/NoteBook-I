# Số Lượng Số Từ 1 -> n Không Chia Hết Cho Bất Kỳ Số Nào Từ 2 -> 10

## Liên  Hệ
* Sàng Nguyên Tố
* Tổ hợp các số tạo ra từ tích của các thừa số nguyên tố p1, p2, p3, ... , pk
* Số lượng các số (chia hết / không chia hêt) cho bất kì các số nguyên tố p1, p2, p3, ... , pk
* [Dạng Tổng Quát: Số Lượng Số Từ a -> b Không Chia Hết Cho Bất Kỳ Số Nào Từ c -> d](./note_2.md)

## Ý Tưởng
* Các số từ 1 -> n không có thừa số nguyên tố từ 2 -> 10
* Số nguyên tố từ 2 đến 10 ( Sàng Nguyên Tố )

## Giải Quyết Vấn Đề
### Cách 1 ( Chọn Trực Tiếp ):
```C++
// Time : O(n)
// Space: O(1)
```
```C++
int res = 0;
for (int i=1; i<=n; i++){
	/// Số Nguyên Tố từ 2->10 : 2, 3, 5, 7
	if ( i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0){
		res++;
	}
}
cout << res;
```
**Ưu Điểm**
* Dễ cài đặt
* Ý tưởng đơn giản

**Khuyết Điểm**
* Độ phức tạp cao

### Cách 2 ( Tính Phần Bù ):
-*Tìm số lượng không chia hết cho các thừa số nguyên tố (2->10) có thể khó tìm công thức. Nhưng tìm các số chia hết cho các thừa số nguyên tố (2->10) lại khá dễ*
-Áp dụng tính chất của các tập hợp: 
A ∪ B ∪ C = (A + B + C) - (A∩B + A∩C + B∩C) + (A∩B∩C)
và **Dạng Tổng Quát**

```C++
// Time: O(1)
// Space: O(1)
```

```C++
int d2 = n/2; // 2
int d3 = n/3; // 3
int d5 = n/5; // 5
int d7 = n/7; // 7

int d6 = n/6; // 2, 3
int d10 = n/10; // 2, 5
int d14 = n/14; // 2, 7
int d15 = n/15; // 3, 5
int d21 = n/21; // 3, 7
int d35 = n/35; // 5, 7

int d30 = n/30; // 2, 3, 5
int d42 = n/42; // 2, 3, 7
int d70 = n/70; // 2, 5, 7
int d105 = n/105; // 3, 5, 7

int d210 = n/210; // 2, 3, 5, 6

int d2_3_5_7 = (d2 + d3 + d5 + d7) - (d6 + d10 + d14 + d15 + d21 + d35) + (d30 + d42 + d70 + d105) - d210; 
ull res = n - d2_3_5_7;
cout << res;
```

**Ưu Điểm**
* Độ phức tạp tốt ( Chỉ tính số lượng chứ không liệt kê rồi đếm nên *Cách 1*, Tính chất số học)

**Khuyết Điểm**
* Tìm tổ hợp các thừa số nguyên tố ( Số lượng tổ hợp: 2^k - 1 | k: số thừa số nguyên tố 

## Ghi Chú
**Số lượng các số từ a -> b (chia hết / không chia hêt) cho bất kì các số nguyên tố p1, p2, p3, ... , pk**
