
---

```markdown
# Sliding Window Maximum (C 語言實作)

本專案實作了 LeetCode 經典問題 [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)，並使用 C 語言自行構建了 **雙端佇列（Deque）資料結構**，以達成線性時間解法。

---

## 🧠 專案特色

- ✅ 使用 **環形陣列 (Circular Array)** 實作高效能的 Deque
- ✅ 解法時間複雜度為 **O(n)**，符合最佳解標準
- ✅ 提供 **互動模式** 及 **測資檔模式**
- ✅ 支援自動化測試並內建記憶體釋放機制
- ✅ 完全用純 C 語言編寫，適合資料結構與系統程式設計練習

---

## 📁 專案結構

.
├── Assignment.md       # 作業說明文件
├── deque.h             # Deque 資料結構與操作定義
├── deque.c             # Deque 的實作
├── main.c              # 主程式：Sliding Window 演算法邏輯
├── tests.txt           # 多組測試案例
├── Makefile            # 編譯腳本
└── sliding_window      # 可執行檔 (編譯後生成)
```

---

## 🚀 快速開始

### 編譯程式

```bash
make
````

會產生名為 `sliding_window` 的執行檔。

---

### 執行程式

#### ✅ 互動模式

```bash
./sliding_window
```

執行後依照提示輸入：

* 窗口大小 `k`
* 陣列長度與內容

#### 📂 測資檔案模式

```bash
./sliding_window tests.txt
```

`tests.txt` 每組測資格式：

```
<k> <n>
<num1> <num2> ... <numN>
```

範例：

```
3 8
1 3 -1 -3 5 3 6 7
```

---

## 💡 解題策略簡述

使用單調遞減的 Deque 儲存「索引」，保證每個窗口的最大值都位於隊首。

演算法步驟：

1. 移除隊尾所有小於目前元素的索引
2. 將目前索引加入 Deque 尾端
3. 若隊首元素已滑出窗口，則移除
4. 當 `i >= k - 1` 時，輸出隊首對應的值作為最大值

---

## 🧪 範例輸出

輸入：

```txt
nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
```

輸出：

```txt
[3, 3, 5, 5, 6, 7]
```

---

## 👨‍💻 開發環境

* 語言：C99
* 編譯器：`gcc`
* 建議平台：Linux / macOS / WSL
* 編譯指令：`make`

---

## 📜 參考來源

* [LeetCode 239 - Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
* 作業提供之說明檔 `Assignment.md`

---

