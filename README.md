
---

```markdown
# 📘 C 語言資料結構實作總覽

本專案集合六大核心資料結構的 C 語言實作，涵蓋實務應用場景與演算法訓練，適合作為學習資料結構與 C 語言進階實作的參考範例。
```
---

## 🔖 專案列表

| 資料結構         | 子專案名稱             | 概要說明 |
|------------------|------------------------|----------|
| ✅ Stack         | `stack`                | 實作括號匹配檢查器，可驗證程式中 `()[]{} ` 是否成對正確嵌套。 |
| ✅ Linked List   | `linked-list`          | 單向鏈結串列，支援新增、刪除、搜尋等基本操作。 |
| ✅ Doubly Linked List | `doubly-linked-list`   | 雙向鏈結串列，支援前後遍歷與靈活插入刪除。 |
| ✅ Struct 應用   | `student-management`   | 學生資料管理系統，結合 `struct` 與 File I/O 實作 CRUD 功能。 |
| ✅ Deque         | `deque`                | 使用環狀陣列實作雙端佇列，應用於「滑動視窗最大值」問題。 |
| ✅ Binary Search Tree | `bst`                  | 實作 BST 插入、搜尋、刪除、遍歷與圖形化顯示（含遞迴與非遞迴實作）。 |

---

## ⚙️ 使用方式（每個子專案皆適用）

1. 進入對應子資料夾（如 `cd stack`）
2. 使用 `make` 編譯
3. 使用 `make run` 執行
4. 可選指令：
   - `make clean`：清除中間產物
   - `make test`：執行自動測試（若支援）
   - `make valgrind`：檢查記憶體洩漏（需安裝 `valgrind`）

---

## 🧠 學習重點總覽

| 類型 | 涵蓋內容 |
|------|----------|
| 資料結構設計 | Stack、Queue、Deque、Linked List、BST |
| 動態記憶體 | malloc / free 運用、記憶體管理觀念 |
| 遞迴處理 | 遞迴遍歷與刪除（如 BST） |
| 模組化 | 分離 `.c` / `.h` 檔案與 Makefile 結構 |
| 錯誤處理 | 使用者輸入錯誤檢查、空指標處理等 |
| 實務應用 | 括號匹配檢查器、學生管理系統、視窗最大值 |

---

## 📂 資料夾結構建議
```
.
├── stack/                    # 括號匹配檢查器
├── linked-list/              # 單向鏈結串列
├── doubly-linked-list/       # 雙向鏈結串列
├── student-management/       # Struct + File I/O 學生系統
├── deque/                    # 雙端佇列 + 滑動視窗
├── bst/                      # 二元搜尋樹系統
└── README.md                 # 本統整文件
```

---

## ✨ 推薦延伸挑戰

- [ ] 將鏈結串列改為泛型（void*）
- [ ] 將 BST 改為平衡樹（如 AVL Tree）
- [ ] 將系統封裝為 Library 並搭配單元測試
- [ ] 移植至嵌入式平台（如 STM32）
- [ ] 製作簡易 GUI 介面或網頁展示（Ex: 括號視覺化）

---

## 🛠️ 環境需求

- GCC / Clang 編譯器
- UNIX-like 終端機（建議 Linux / macOS 或 Windows WSL）
- 可選工具：`valgrind`, `gdb`, `make`

---
