# minitalk #
UNIX sinyalleriyle (SIGUSR1 / SIGUSR2) çalışan client-server mesajlaşma uygulaması.
Amaç: Sinyal tabanlı asenkron iletişim öğrenmek.
Neler öğrendim ?
-UNIX sinyalleri (SIGUSR1, SIGUSR2) ile prosesler arası iletişim (IPC) uyguladım.
-Asenkron programlama kavramını öğrendim: sinyal geldiğinde uygun callback fonksiyonunun çalıştırılması.
-Proses yönetimi (getpid(), kill()) bilgimi geliştirdim.
-Client-server mimarisi kurdum ve iletişim protokolü geliştirdim.
-Reliable communication (mesaj kaybını önleme) için onaylama (acknowledgement) ve retry logic geliştirdim.
-Gerçek zamanlı sistem programlama için temel bilgiler edindim.
