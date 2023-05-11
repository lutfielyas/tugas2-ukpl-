#include <iostream>
#include <string>

using namespace std;

// 1. mendefinisikan enumerasi State yang mencakup semua state yang mungkin dalam keadaan mesin.
// Dalam kasus ini, ada empat state: STATE_IDLE, STATE_LOGIN, STATE_AUTHENTICATED, dan STATE_BLOCKED.
enum State {
  STATE_IDLE,
  STATE_LOGIN,
  STATE_AUTHENTICATED,
  STATE_BLOCKED
};

// 1. mendefinisikan class UserLoginStateMachine yang merepresentasikan keadaan mesin untuk skenario login pengguna.

// 2. Di dalam class UserLoginStateMachine, kita memiliki variabel anggota private currentState untuk melacak state saat ini,
// dan loginAttempts untuk menghitung jumlah percobaan login yang dilakukan oleh pengguna.

// 3. Constructor UserLoginStateMachine() digunakan untuk menginisialisasi currentState ke STATE_IDLE
// dan loginAttempts ke 0 saat objek dibuat.
class UserLoginStateMachine {
public:
  UserLoginStateMachine() {
    currentState = STATE_IDLE;
    loginAttempts = 0;
  }

  // 1. Fungsi transitionToNextState() digunakan untuk melakukan transisi ke state berikutnya
  // berdasarkan input isLoggedIn yang menunjukkan apakah pengguna berhasil login (true)
  // atau gagal login (false). Dalam fungsi ini, kita menggunakan switch-case untuk
  // menentukan state berikutnya berdasarkan state saat ini dan jumlah percobaan login.
  // Jika pengguna gagal login dua kali, maka state akan berubah menjadi STATE_BLOCKED.
  void transitionToNextState(bool isLoggedIn) {
    switch (currentState) {
      case STATE_IDLE:
        if (isLoggedIn) {
          currentState = STATE_AUTHENTICATED;
          loginAttempts = 0;
        }
        else
          currentState = STATE_LOGIN;
        break;
      case STATE_LOGIN:
        if (isLoggedIn) {
          currentState = STATE_AUTHENTICATED;
          loginAttempts = 0;
        }
        else {
          loginAttempts++;
          if (loginAttempts >= 2)
            currentState = STATE_BLOCKED;
        }
        break;
      case STATE_AUTHENTICATED:
        // Transisi ke menu berikutnya
        // ...

        break;
      case STATE_BLOCKED:
      	cout << endl;
        cout << "AKUN PENGGUNA DIBLOKIR!" << endl;
        break;
      default:
        cout << "State tidak valid!" << endl;
        break;
    }
  }

  // Fungsi getCurrentState() mengembalikan state saat ini dari currentState.
  State getCurrentState() {
    return currentState;
  }

  // 1. Fungsi printCurrentState() digunakan untuk mencetak state saat ini ke layar.
  // Ini mencetak pesan dengan menggunakan cout dan menampilkan stateName yang sesuai dengan state saat ini.
  void printCurrentState() {
      string stateName;
      
    switch (currentState) {
      case STATE_IDLE:
        stateName = "STATE_IDLE";
        break;
      case STATE_LOGIN:
        stateName = "STATE_LOGIN";
        break;
      case STATE_AUTHENTICATED:
        stateName = "STATE_AUTHENTICATED";
        break;
      case STATE_BLOCKED:
        stateName = "STATE_BLOCKED";
        break;
      default:
        stateName = "Unknown State";
        break;
    }
    
	cout << endl;
	cout << "================================";
	cout << endl;
    cout << "State saat ini: " << stateName << endl;
    cout << "================================";
    cout << endl << endl;
    system ("pause");
    cout << endl;
  }

private:
  State currentState;
  int loginAttempts;
};

int main() {
  bool repeatProgram = true;

  while (repeatProgram) {
    UserLoginStateMachine machine;

    bool isLoggedIn = false;
    string input;

// 1. loop while (true) yang akan meminta pengguna untuk memasukkan status login menggunakan angka yang sesuai.
// Input pengguna disimpan dalam variabel input. Dalam loop ini, machine.printCurrentState() dipanggil
// untuk mencetak state saat ini ke program.
    while (true) {
      machine.printCurrentState();
      cout << "Masukkan Status Login (By Number)" << endl;
    	cout << "1 untuk berhasil login" << endl;
       	cout << "2 untuk Gagal Login" << endl;
       	cout << "3 untuk Mengulang Program" << endl;
       	cout << "Picked Number : "; 
		cin >> input;

      if (input == "1") {
        isLoggedIn = true;
      }
      else if (input == "2") {
        isLoggedIn = false;
      }
      else if (input == "3") {
      	system("cls");
        main();
        break;
      }
      else {
        cout << "Input tidak valid!" << endl;
        continue;
      }

      machine.transitionToNextState(isLoggedIn);

      if (machine.getCurrentState() == STATE_BLOCKED) {
      	cout << endl;
        cout << "AKUN PENGGUNA DIBLOKIR!" << endl;
        
        break;
      }
    }
  }

  return 0;
}

