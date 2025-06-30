# 📡 minitalk - UNIX Sinyalleriyle Mesajlaşma

`minitalk`, yalnızca **UNIX sinyalleri** (`SIGUSR1`, `SIGUSR2`) kullanarak çalışan bir **client-server mesajlaşma sistemidir**. Her karakter, bit düzeyinde sinyallerle iletilir. Projenin amacı, sinyal temelli IPC (Inter-Process Communication) yapısını öğrenmek ve güvenilir bir protokol geliştirmektir.

---

## 🎯 Proje Amacı

- UNIX sinyalleri ile prosesler arası mesaj iletimi
- Client → Server yönünde **asenkron karakter aktarımı**
- Server'dan client'a ACK (onay) gönderimi
- Gerçek zamanlı, düşük seviyeli iletişim deneyimi kazanmak

---

## 🧠 Neler Öğrendim?

### 📶 UNIX Signals & IPC
- `SIGUSR1` ve `SIGUSR2` kullanarak **binary data** gönderimini öğrendim.
- `kill(pid, signal)` ile başka bir prosese sinyal gönderme yeteneği kazandım.
- `signal()` ve `sigaction()` ile sinyal geldiğinde **callback handler** tetiklemeyi uyguladım.

### 🔁 Asenkron Programlama
- Her bit gönderimi sonrası ACK (acknowledgement) bekleyerek **güvenilir iletişim protokolü** tasarladım.
- Zamanlama, mesaj kaybı ve yeniden gönderme (retry) gibi konularda sağlamlık sağladım.

### 🧱 Client-Server Mimari
- Server: gelen sinyalleri dinler, bir karaktere dönüştürür ve stdout'a basar.
- Client: verilen PID'e karakterleri bit bit sinyallerle gönderir.

### 🕹️ Proses Yönetimi
- `getpid()` ile server PID’si, `kill()` ile mesaj gönderimi
- Birden fazla client ile iletişim için güvenli yapı oluşturma

---

## 💻 Kullanım

### 🧩 Derleme

```bash
make

🛰️ Server Başlat
./server
Server PID: 12345
📨 Client ile Mesaj Gönder
./client 12345 "Merhaba Dünya"

🔐 Güvenlik ve Sağlamlık

✅ ACK sistemi ile her karakter doğrulandı
✅ Memory leak ve race condition yok
✅ Çoklu client destekli yapı
✅ Sistem sinyalleri dışında hiçbir iletişim aracı kullanılmadı
