# 執行方式
- 編譯並執行 bsd.cpp
> g++ -c binarySearchDynamic.cpp
> g++ binarySearchDynamic.o bsd.cpp
> ./a.out N 
Note: N 是欲執行的資料筆數
- 編譯並執行rbt.cpp
> g++ rbt.cpp -o b.out
> ./b.out N
Note: N 是欲執行的資料筆數
- 進行測試
> ./experiment.sh
> N
Note: 執行後輸入資料比數 N 將自動執行腳本將時間輸出於 bsd.txt、rbt.txt

# 檔案說明
- binarySearchDynamic.cpp: 主要程式碼
- binarySearchDynamic.h: 定義資料結構 class 檔案
- bsd.cpp: 本專案 binarySearchDynamic 測試程式
- rbt.cpp: 紅黑樹測試程式
- a.out: bsd.cpp 執行檔
- b.out: rbt.cpp 執行檔
- experiment.sh: 測試執行腳本，自動執行a.out b.out 並輸出結果
- bsd.txt: 本專案測試數據
- rbt.txt: 紅黑樹測試數據
- Paper: 報告儲存資料夾
- 111502563林橋毅-Project2.pdf: 報告 pdf 檔案
