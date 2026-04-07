*This activity has been created as part of the 42 curriculum by seguler, vaktas.*

# push_swap - @42Istanbul

EN:

## Description

`push_swap` is a sorting project from the 42 curriculum. The goal is to sort a stack of unique integers using a limited set of stack operations and to do so with as few operations as possible.

This repository contains the full implementation of the project, including parsing, error handling, stack operations, sorting strategies, benchmarking helpers, and a Linux checker for validation.

## Instructions

### Compilation

Build the project with:

```bash
make
```

Clean generated files with:

```bash
make clean
make fclean
make re
```

### Execution

Run the program by passing a list of integers as arguments:

```bash
./push_swap 4 67 3 9 1
```

The program prints the sequence of operations needed to sort the input stack in ascending order.

### Validation

You can verify the output with the provided checker:

```bash
./push_swap 4 67 3 9 1 | ./checker_linux 4 67 3 9 1
```

### Flags

The program supports the following flags:

- `--simple` : force the simple strategy
- `--medium` : force the medium strategy
- `--complex` : force the complex strategy
- `--adaptive` : use the adaptive strategy
- `--bench` : enable benchmark output

Example:

```bash
./push_swap --adaptive 4 67 3 9 1
./push_swap --bench --complex 4 67 3 9 1
```

## Algorithms

This project includes multiple sorting strategies so the program can choose the most appropriate one depending on the input size and disorder level.

### Simple strategy — O(n²)

The simple approach is designed for very small inputs.

- It handles the smallest stack sizes directly with minimal stack operations.
- For 2 and 3 elements, direct comparisons and swaps/rotations are enough.
- For 5 elements, the algorithm pushes the smallest values away, sorts the remaining 3 elements, then restores the saved elements.

This strategy is easy to reason about and is efficient for tiny inputs because the constant cost of more advanced methods would not be justified.

### Medium strategy — O(n√n)

The medium strategy is a chunk-based approach.

- The stack is processed in groups of values.
- Elements are pushed to stack B in controlled ranges.
- The next best element is repeatedly moved to the top of B and pushed back to A.

The strategy is intended to reduce the number of rotations compared to a naive method, especially for mid-sized inputs. Its chunked behavior aims for a balance between speed and operation count.

### Complex strategy — O(n log n)

The complex strategy is the most scalable option for larger inputs.

- It uses index-based ordering.
- Elements are processed bit by bit using a radix-style method.
- Each pass separates values according to the current bit, then reconstructs the sorted stack.

This strategy is selected because it remains stable and predictable on large data sets. It is especially useful when a consistently low operation count is needed.

### Adaptive strategy

The adaptive strategy chooses between the available algorithms based on the input disorder.

- Low disorder inputs are handled by the simpler approach.
- Medium disorder inputs use the medium strategy.
- Highly disordered inputs use the complex strategy.

This improves overall performance by matching the algorithm to the input characteristics instead of always using the same method.

## Resources

### References

- 42 push_swap subject and project requirements
- Stack operation rules from the 42 curriculum
- General algorithm references for selection sort, chunk-based sorting, and radix sorting
- GNU Bash documentation for the test scripts
- Checker workflow used to validate outputs

### AI usage

AI was used for:

- Drafting and structuring this README
- Improving wording, formatting, and section organization
- Summarizing the algorithm choices in a clear documentation style
- Helping interpret test failures during debugging

AI was not used to replace the project implementation. The sorting logic, stack operations, and final validation remained part of the project codebase and were reviewed and adjusted by the learners.

## Learner Contributions

### seguler

- Implemented and refined the core sorting logic
- Worked on stack operations and algorithm selection
- Helped validate the test suite and performance behavior

### vaktas

- Implemented and refined parsing, error handling, and memory management
- Worked on benchmarking, test automation, and validation
- Helped debug failing cases and verify fixes across test scenarios

Both learners contributed to reviewing the code, validating the behavior with the checker, and ensuring the repository matches the project requirements.



*Bu etkinlik, seguler ve vaktas tarafından 42 müfredatının bir parçası olarak oluşturulmuştur.*

# push_swap - @42Istanbul

TR:

## Açıklama

`push_swap`, 42 müfredatından bir sıralama projesidir. Amaç, sınırlı sayıda yığın işlemi kullanarak ve mümkün olduğunca az işlemle benzersiz tamsayıların bir yığınını sıralamaktır.

Bu depo, ayrıştırma, hata işleme, yığın işlemleri, sıralama stratejileri, kıyaslama yardımcıları ve doğrulama için bir Linux denetleyicisi de dahil olmak üzere projenin tam uygulamasını içerir.

## Talimatlar

### Derleme

Projeyi şu komutlarla derleyin:

```bash
make
```

Oluşturulan dosyaları şu komutlarla temizleyin:

```bash
make clean
make fclean
make re
```

### Çalıştırma

Programı, argüman olarak bir tamsayı listesi geçirerek çalıştırın:

```bash
./push_swap 4 67 3 9 1
```

Program, giriş yığınını artan sırada sıralamak için gereken işlem dizisini yazdırır.

### Doğrulama

Çıktıyı sağlanan denetleyici ile doğrulayabilirsiniz:

```bash
./push_swap 4 67 3 9 1 | ./checker_linux 4 67 3 9 1
```

### Bayraklar

Program aşağıdaki bayrakları destekler:

- `--simple` : basit stratejiyi zorla
- `--medium` : orta stratejiyi zorla
- `--complex` : karmaşık stratejiyi zorla
- `--adaptive` : uyarlanabilir stratejiyi kullan
- `--bench` : kıyaslama çıktısını etkinleştir

Örnek:

```bash
./push_swap --adaptive 4 67 3 9 1
./push_swap --bench --complex 4 67 3 9 1
```

## Algoritmalar

Bu proje, programın giriş boyutuna ve düzensizlik seviyesine bağlı olarak en uygun olanı seçebilmesi için birden fazla sıralama stratejisi içerir.

### Basit strateji — O(n²)

Basit yaklaşım, çok küçük girişler için tasarlanmıştır.

- En küçük yığın boyutlarını minimum yığın işlemleriyle doğrudan ele alır.

- 2 ve 3 eleman için doğrudan karşılaştırmalar ve takas/döndürmeler yeterlidir.

- 5 eleman için algoritma en küçük değerleri kenara iter, kalan 3 elemanı sıralar ve ardından kaydedilen elemanları geri yükler.

Bu strateji anlaşılması kolaydır ve küçük girdiler için verimlidir çünkü daha gelişmiş yöntemlerin sabit maliyeti haklı çıkarılamaz.

### Orta strateji — O(n√n)

Orta strateji, öbek tabanlı bir yaklaşımdır.

- Yığın, değer grupları halinde işlenir.

- Elemanlar, kontrollü aralıklarla B yığınına itilir.

- Bir sonraki en iyi eleman, tekrar tekrar B'nin üstüne taşınır ve A'ya geri itilir.

Bu strateji, özellikle orta büyüklükteki girdiler için, basit bir yönteme kıyasla döndürme sayısını azaltmayı amaçlamaktadır. Öbekli davranışı, hız ve işlem sayısı arasında bir denge kurmayı hedefler.

### Karmaşık strateji — O(n log n)

Karmaşık strateji, daha büyük girdiler için en ölçeklenebilir seçenektir.

- İndeks tabanlı sıralama kullanır.

- Elemanlar, radiks tarzı bir yöntem kullanılarak bit bit işlenir.

- Her geçiş, değerleri mevcut bite göre ayırır ve ardından sıralanmış yığını yeniden oluşturur.

Bu strateji, büyük veri kümelerinde kararlı ve tahmin edilebilir kaldığı için seçilmiştir. Özellikle sürekli olarak düşük işlem sayısına ihtiyaç duyulduğunda kullanışlıdır.

### Uyarlanabilir strateji

Uyarlanabilir strateji, girdi düzensizliğine bağlı olarak mevcut algoritmalar arasında seçim yapar.

- Düşük düzensizlikteki girdiler daha basit yaklaşımla işlenir.

- Orta düzensizlikteki girdiler orta stratejiyi kullanır.

- Yüksek düzensizlikteki girdiler karmaşık stratejiyi kullanır.

Bu, her zaman aynı yöntemi kullanmak yerine algoritmayı girdi özelliklerine uyarlayarak genel performansı iyileştirir.

## Kaynaklar

### Referanslar

- 42 push_swap ders ve proje gereksinimleri
- 42 müfredatından yığın işlemi kuralları
- Seçim sıralaması, öbek tabanlı sıralama ve radiks sıralama için genel algoritma referansları
- Test komut dosyaları için GNU Bash dokümantasyonu
- Çıktıları doğrulamak için kullanılan denetleyici iş akışı

### Yapay Zeka Kullanımı

Yapay zeka şu amaçlarla kullanılmıştır:

- Bu README dosyasının taslağının hazırlanması ve yapılandırılması
- Kelime seçiminin, biçimlendirmenin ve bölüm organizasyonunun iyileştirilmesi
- Algoritma seçimlerinin açık bir dokümantasyon stiliyle özetlenmesi
- Hata ayıklama sırasında test hatalarının yorumlanmasına yardımcı olunması

Yapay zeka, proje uygulamasının yerini almak için kullanılmamıştır. Sıralama mantığı, yığın işlemleri ve son doğrulama, proje kod tabanının bir parçası olarak kalmış ve öğrenciler tarafından gözden geçirilip ayarlanmıştır.

## Öğrenci Katkıları

### seguler

- Temel sıralama mantığını uyguladı ve geliştirdi
- Yığın işlemleri ve algoritma seçimi üzerinde çalıştı
- Test paketinin ve performans davranışının doğrulanmasına yardımcı oldu

### vaktas

- Ayrıştırma, hata işleme ve bellek yönetimini uyguladı ve geliştirdi
- Performans karşılaştırması, test otomasyonu ve doğrulama üzerinde çalıştı
- Başarısız olan durumların hata ayıklamasına ve test senaryoları genelinde düzeltmelerin doğrulanmasına yardımcı oldu

Her iki öğrenci de kodun incelenmesine, denetleyici ile davranışın doğrulanmasına ve deponun proje gereksinimlerine uygun olmasının sağlanmasına katkıda bulundu.