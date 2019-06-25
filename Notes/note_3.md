# Số lượng các số từ a -> b (chia hết / không chia hêt) cho bất kì các số nguyên tố p1, p2, p3, ... , pk

## Liên Hệ
* [Số Lượng Số Từ 1 -> n Không Chia Hết Cho Bất Kỳ Số Nào Từ 2 -> 10](./note_1.md)
* [Số Lượng Số Từ a -> b Không Chia Hết Cho Bất Kỳ Số Nào Từ c -> d](./note_2.md)

## Giải Quyết Vấn Đề

### Tính Phần Bù
* Áp dụng tính chất của các tập hợp: A ∪ B ∪ C = (A + B + C) - (A∩B + A∩C + B∩C) + (A∩B∩C) và Dạng Tổng Quát
* **Ví Dụ**: tìm các số từ 10 -> 100 chia hết cho bất kì 5, 7, 19. 

```
1) [5] ∪ [7] ∪ [19] = ([5] + [7] + [9]) - ([5, 7] + [5, 19] + [7, 19]) + ([5, 7, 19])
2) [k] từ 1->n:[k] = n/k
3) [5, 7] = [5] ∩ [7]
```

```C++
// Từ 1->100
int d5 = 100/5;
int d7 = 100/7;
int d19 = 100/19;
int d57 = 100/(5*7);
int d519 = 100/(5*19);
int d719 = 100/(7*19);
int d5719 = 100/(5*7*19);
int res1 = (d5 + d7 + d19) - (d57 + d519 + d719) + (d5719)

// Từ 1->10
int d5 = 10/5;
int d7 = 10/7;
int d19 = 10/19;
int d57 = 10/(5*7);
int d519 = 10/(5*19);
int d719 = 10/(7*19);
int d5719 = 10/(5*7*19);
int res2 = (d5 + d7 + d19) - (d57 + d519 + d719) + (d5719)

// Từ 10 -> 100
int res = res1 - res2
```

**Tổng Quát**
```
*[p1] ∪ [p2] ∪ [p3] ∪ ...∪ [pk] = 
([p1] + [p2] + [p3] + ...+ [pk]) 
- ([p1, p2] + [p1, p3] + [p1, p4]) + ...+ [pk-1, pk]) 
+ ([p1, p2, p3] + [p1, p2, p4] + [p1, p2, p5]) + ...+ [pk-2, pk-1, pk]) 
+ ... (+/-) ([p1, p2, p3, ..., pk] // +: k lẻ, -: k chẵn
```
```C++
// Từ 1->b
int dp1 = b/p1;
int dp2 = b/p2;
int dp3 = b/p3;
...
int dpk = b/pk;

int dp1p2 = b/(p1*p2);
int dp1p3= b/(p1*p3);
int dp1p4 = b/(p1*p4);
...
int dpk_1pk = b/(pk_1*pk);

...
int dp1p2p3...pk_1pk = b/(p1*p2*p3*...pk_1*pk);

int res1 = (dp1 + dp2 + dp3 + ...+ dpk) - (dp1p2 + dp1p3 + dp1p4 + ...+dpk_1pk) +... (+/-) (dp1p2p3...pk_1pk)

// Từ 1->a
int dp1 = a/p1;
int dp2 = a/p2;
int dp3 = a/p3;
...
int dpk = a/pk;

int dp1p2 = a/(p1*p2);
int dp1p3= a/(p1*p3);
int dp1p4 = a/(p1*p4);
...
int dpk_1pk = a/(pk_1*pk);

...
int dp1p2p3...pk_1pk = a/(p1*p2*p3*...pk_1*pk);

int res2 = (dp1 + dp2 + dp3 + ...+ dpk) - (dp1p2 + dp1p3 + dp1p4 + ...+dpk_1pk) +... (+/-) (dp1p2p3...pk_1pk)

// Từ a -> b
int res = res1 - res2
```

### Dùng Mảng Đánh Dấu
* Giải Thuật Tương Từ Sàng Nguyên Tố Eratosthenes 

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

## Chú Thích
**Số có tính chất (chia hết/ không chia hết) bất kì cho tập các số (a1, a2, a3,...ak)**
