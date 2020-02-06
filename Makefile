CFLAGs=-w -g

all:
	gcc -w -g Main_Runnable.c Decrypt_Encrypt.c -o Vigene_Cipher.a

clean:
	rm -f Vigene_Cipher.a