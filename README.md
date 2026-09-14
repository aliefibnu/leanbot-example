# Synapse City Command Generator

Aplikasi web generator dan simulator string instruksi robot Leanbot untuk kompetisi **Synapse City**.

---

## 📖 Dokumentasi Protokol Perintah (Command Protocol)

Robot Leanbot dikendalikan menggunakan rangkaian string instruksi (command sequence) yang dieksekusi secara berurutan. Format penulisan mendukung mode **Standar** (default dengan pemisah koma `, `) dan mode **Compact**.

---

### 1. Pergerakan Dasar (Grid & 90°)

| Kode Standar | Kode Compact | Nama Perintah | Deskripsi & Fungsi |
| :---: | :---: | :--- | :--- |
| `F` | `F` | **Maju (Forward)** | Robot bergerak maju sejauh 1 petak grid atau hingga mendeteksi persimpangan garis lintasan berikutnya. |
| `R` | `R` | **Kanan 90° (Right)** | Pivot turn (putar di tempat) 90 derajat searah jarum jam (ke kanan). |
| `L` | `L` | **Kiri 90° (Left)** | Pivot turn (putar di tempat) 90 derajat berlawanan arah jarum jam (ke kiri). |
| `B` | `B` | **Putar Balik (Back / U-Turn)** | Putar balik 180 derajat di tempat untuk membalikkan arah hadap robot. |

---

### 2. Pergerakan Jarak Presisi (10cm)

| Kode Standar | Kode Compact | Nama Perintah | Deskripsi & Fungsi |
| :---: | :---: | :--- | :--- |
| `F10` | `f` | **Maju 10cm (Forward 10cm)** | Robot bergerak maju lurus sejauh 10 cm secara presisi (menggunakan encoder/timer motor) tanpa mengandalkan sensor garis persimpangan. |
| `B10` | `b` | **Mundur 10cm (Backward 10cm)** | Robot bergerak mundur lurus sejauh 10 cm secara presisi untuk mundur dari obstacle atau penyesuaian posisi drop. |

---

### 3. Rotasi Sudut Halus (Turn 45° & 10°)

| Kode Standar | Kode Compact | Nama Perintah | Deskripsi & Fungsi |
| :---: | :---: | :--- | :--- |
| `R45` | `r` | **Kanan 45° (Turn Right 45°)** | Putar kanan 45 derajat. Digunakan untuk bermanuver di jalur diagonal arena atau pendekatan sudut. |
| `L45` | `l` | **Kiri 45° (Turn Left 45°)** | Putar kiri 45 derajat. Digunakan untuk bermanuver di jalur diagonal arena atau pendekatan sudut. |
| `R10` | `x` | **Kanan 10° (Nudge Right 10°)** | Koreksi sudut mikro 10 derajat ke kanan untuk kalibrasi lurus atau orientasi halus. |
| `L10` | `y` | **Kiri 10° (Nudge Left 10°)** | Koreksi sudut mikro 10 derajat ke kiri untuk kalibrasi lurus atau orientasi halus. |

---

### 4. Aksi Mekanisme & Delay (Gripper & Delay)

| Kode Standar | Kode Compact | Nama Perintah | Deskripsi & Fungsi |
| :---: | :---: | :--- | :--- |
| `C` | `C` | **Capit (Catch / Clamp)** | Mengaktifkan motor servo gripper untuk menutup dan menjepit objek (blok polusi / netralizer). |
| `D` | `D` | **Lepas (Drop / Release)** | Membuka servo gripper untuk melepaskan objek di zona target / depot pembuangan. |
| `W` | `W` | **Tunggu (Wait / Delay)** | Jeda diam selama 2 detik untuk stabilisasi, sinkronisasi alur, atau menghindari tabrakan antar robot di persimpangan. |

---

## ⚙️ Format Pemisah (Separators)

1. **Koma (Default)**: `F, R, F10, C, W, D`
   - Sangat mudah dibaca manusia dan membedakan token multi-karakter (`F10`, `R45`).
2. **Spasi**: `F R F10 C W D`
   - Cocok untuk pengiriman serial / parsing berbasis spasi.
3. **Rapat (None)**: `FRF10CWD` (Standar) atau `FRfcWD` (Compact)
   - Payload data berukuran paling kecil untuk efisiensi transfer wireless/Bluetooth.

---

## ⌨️ Shortcut Keyboard

Aplikasi mendukung input cepat langsung dari keyboard:
- `F` : Tambah Maju (Forward)
- `R` : Tambah Kanan 90°
- `L` : Tambah Kiri 90°
- `B` : Tambah Putar Balik
- `C` : Tambah Capit (Catch)
- `D` : Tambah Lepas (Drop)
- `W` / `Space` : Tambah Tunggu (Wait)
- `Backspace` : Hapus perintah terakhir

---

## 🚀 Setup & Menjalankan Project

```bash
# Install dependensi
npm install

# Jalankan development server
npm run dev

# Build untuk production
npm run build
```
