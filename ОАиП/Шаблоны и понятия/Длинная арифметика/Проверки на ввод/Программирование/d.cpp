/***********************************************************************************************************************
Задача UniLecs №273: https://telegra.ph/Anons-273-Najti-podmassivy-gde-summa-ehlementov-ravna-zadannomu-chislu-K-06-11
Решение задачи о поиске кол-ва подмассивов, где сумма элементов равна заданному числу.
________________________________________________________________________________________________________________________
Идея решения с линейной сложностью довольна проста. Заводим хеш-таблицу (unordered_map), ключом которого будет сумма,
а значением – кол-во таких сумм. Инициализируем переменную current_sum = 0 (сумму элементов от начала массива). Далее
перебираем все элементы исходного массива и внутри цикла делаем следующие шаги:
1. Увеличиваем на единицу значение в хеш-таблице по ключу, равному current_sum (сумме элементов от начала массива до
предшествующего элемента). Для нулевой суммы в начале цикла это тоже нужно сделать, чтобы увеличивать результат при
current_sum = sum, где sum – искомая сумма.
2. Увеличиваем current_sum на значение текущего элемента.
3. Ищем в хеш-таблице ключ, равный разнице current_sum и sum. В случае успеха прибавляем к результату значение из хеш-
таблицы по этому ключу.
Всё, после цикла мы получим искомое кол-во подмассивов.
***********************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Calculate subarray count with specified sum
size_t subarray_sum(const vector<int>& data, long long sum)
{
  std::unordered_map<long long, size_t> sum_counts;
  long long current_sum = 0;
  size_t result = 0;

  // Main loop
  for (const auto n : data) {
    ++sum_counts[current_sum];  // zero sum must be present too ;)
    current_sum += n;
    auto count = sum_counts.find(current_sum - sum);
    if (count != sum_counts.end()) {
      result += count->second;
    }
  }
  return result;
} // subarray_sum

// Display list
void show_list(const vector<int>& data)
{
  cout << '{';
  bool first = true;
  for (const auto n : data) {
    if (!first) {
      cout << ',';
    } else { first = false; }
    cout << ' ' << n;
  }
  cout << " }";
} // show_list

// Calculate sum and display list & result
void calc_and_show(const vector<int>& data, long long sum)
{
  show_list(data);
  cout << ", sum = " << sum << " : " << subarray_sum(data, sum) << " subarrays" << endl;
} // calc_and_show

int main()
{
  int n;int k;int ans=0;
std::cin>>n>>k;
vector<int> data;
for (int i=0;i<n;i++)
{
  long double r;
  cin>>r;
 data.push_back(r);
}
std::cout<<subarray_sum( data,  k);
} 