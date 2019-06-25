# Số Lượng Số Từ a -> b Không Chia Hết Cho Bất Kỳ Số Nào Từ c -> d
## Liên  Hệ
* Sàng Nguyên Tố
* [Số Lượng Số Từ 1 -> n Không Chia Hết Cho Bất Kỳ Số Nào Từ 2 -> 10](./note_1.md)

## Ý Tưởng
Tiếp nối của cách 2 (#1)

## Giải Quyết Vấn Đề

### Cách 2 (#1)
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

#### Các Bước Giải Quyết

```
[1] Tìm các số nguyên tố từ c -> d
[2] Tìm tổ hợp từ các số nguyên tố vừa tìm
[3] Tìm số lượng số phần tử của mỗi tổ hợp từ (1->a, 1->b)
[4] Tìm số lượng số từ a -> b chia hết cho bất kỳ số nào từ c -> d ( [1->b] - [1-a] )
[5] Tính phần bù ( Kết Quả )
```

#### Độ Phức Tạp
```python
[1] O(d*loglog(d)) (Sàng Eratosthenes), O(d) (Sàng Atkin)
[2] O(2^k) (s: số lượng số nguyên tố)
[3] O(2^k) (2^k-1 là số lượng tổ hợp)
[4] O(k)
[5] O(1)
=> O(2^k)
```

### Cách 3 (#1)
* Tổng quát hóa *Cách 3* dễ dàng hơn *Cách 2*

```C++
// pi là số nguyên tố thứ i, k: số lượng số nguyên tố từ c->d
// Time: O(sum(b/p1 + b/p2 + ...+ b/pk)) 
// Space: O(k)
```

```C++
int res = 0;
vector <int> Primes;
// Tìm Các số nguyên tố từ c->d => Primes
bool Sieve[maxc];
memset(Sieve, true, sizeof(Sieve));
for (int i=0; i<Primes.size(); i++){
	for (int j=Primes[i]; j<=b; j+=Primes[i]){
		Sieve[j] = false;
	}	
}
for (int i=a; i<=b; i++){
	if (Sieve[i]){
		res++;
	}
}
cout << res;
```

## So Sánh *Cách 2* và *Cách 3*

* *Cách 2*: O(2^k)
* *Cách 3*: O(sum(b/p1 + b/p2 + ...+ b/pk))

* Khuyết điểm chết người ở *Cách 2* là tìm **Tổ Hợp** của các thừa số nguyên tố (*O(2^k))* 
* Khuyết điểm của cách 3 là a->b lớn thì không hiệu quả lắm. Nhưng tổng thể thì *Cách 3* ổn định hơn các 2
* Với c->d nhỏ hoặc được xác định thì nên dùng cách 2

