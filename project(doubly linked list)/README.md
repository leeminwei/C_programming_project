以下內容已以 **Markdown** 撰寫，直接複製貼上到 `README.md` 即可在 GitHub 上呈現。若需英文化或再調整排版，可再告訴我！

---

# 📚 圖書館借閱管理系統 (C)

> 一個以 **雙向環狀串列 (Borrowed List)** ＋ **雙向線性串列 (Hot List)** 為核心的 CLI 圖書館管理範例，示範在 C 語言中如何安全、低耦合地操作動態資料結構，並維護熱門書籍排行榜。

---

## 目錄

* [專案特色](#專案特色)
* [功能總覽](#功能總覽)
* [程式架構](#程式架構)
* [建置與執行](#建置與執行)
* [操作教學](#操作教學)
* [檔案結構](#檔案結構)
---

## 專案特色

| # | 亮點          | 說明                                    |
| - | ----------- | ------------------------------------- |
| 1 | **雙向環狀串列**  | 借閱書籍清單以環狀結構實作，可 O(1) 由尾端回到頭端，易於巡覽與插刪。 |
| 2 | **熱門書籍排行**  | 以借閱次數門檻與容量上限維護“Hot List”，展示資料結構間的互動。  |
| 3 | **最小記憶體佔用** | 只做必要 `malloc/free`，避免記憶體流失。           |
| 4 | **完整防呆**    | 包含串列空、單節點、ID 不存在等例外處理。                |
| 5 | **易於擴充**    | 模組化函式介面，可快速嵌入檔案 I/O、資料庫或網路層。          |

---

## 功能總覽

| 代號 | 功能              | 主要 API                 |
| -- | --------------- | ---------------------- |
| 1  | 顯示已借閱書籍清單       | `displayBorrowedBooks` |
| 2  | 顯示熱門書籍清單        | `displayHotBooks`      |
| 3  | 借閱書籍（新增 / 次數累計） | `borrowBook`           |
| 4  | 歸還書籍（移除）        | `returnBook`           |
| 5  | 更新熱門書籍清單        | `updateHotBooks`       |
| 6  | 結束並釋放所有資源       | `cleanList`            |

---

## 程式架構

```mermaid
flowchart LR
  subgraph Borrowed List (circular)
    B1["Node\n(id, bookname, author, time)"] -- next / prev --> B2["..."]
    B2 --> B3["..."]
    B3 -- 回到頭 --> B1
  end

  subgraph Hot List (linear)
    H1["Node\n(id, bookname, author)"] -- next --> H2["..."] --> H3["..."]
  end
```

* **`Node`**

  ```c
  typedef struct Node {
      int   id;
      char  bookname[MAX];
      char  author[MAX];
      int   time;        // 借閱次數
      struct Node *next;
      struct Node *prev;
  } Node;
  ```

* **`DoubleLinkedList`**

  ```c
  typedef struct {
      Node *head;
      Node *tail;
      int   size;
  } DoubleLinkedList;
  ```

---

## 建置與執行

> 測試環境：`gcc 13.2`、`clang 18`、`Windows/Linux/macOS` 皆可

```bash
# 1. 取得原始碼
git clone https://github.com/leeminwei/C_programming_project
cd project(doubly linked list)

# 2. 編譯
gcc -Wall -Wextra -pedantic -std=c17 -o main main.c

# 3. 執行
./main
```

> 如使用 `clang` 或需導出至 IDE（VSCode / CLion），僅需將 `main.c` 納入專案並指定 C17 標準。

---

## 操作教學

```
====== 圖書館管理系統 ======
1. 顯示已借閱書籍清單
2. 顯示熱門書籍清單
3. 添加已借閱書籍
4. 刪除已借閱書籍
5. 更新熱門書籍清單
6. 結束程式並清理環境
請輸入選項：
```

> * **借閱書籍** 完整流程
>
>   1. 輸入 **ID** → 若該書已存在，直接累計 `time`
>   2. 否則輸入書名、作者，系統自動插入至尾端
> * **歸還書籍**
>
>   * 支援刪首節點、尾節點、中間節點以及單節點情況
> * **更新熱門書籍清單**
>
>   * 內建門檻 `hotListCapacity = 2`（可於 `main` 修改）
>   * 若 Hot List 已滿，刪除最舊資料（頭節點）

---

## 檔案結構

```text
.
├── main.c           # 主程式：所有核心結構與功能
└── README.md        # 專案說明（本檔）
```

