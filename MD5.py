
#/user/bin/python3
import hashlib

def generate_md5_hash(text):
    md5_hash = hashlib.md5()
    md5_hash.update(text.encode('utf-8'))
    return md5_hash.hexdigest()
def main():
    text = input("Enter the text : ")
    md5_hash = generate_md5_hash(text)
    print("MD5 hash : ",md5_hash)

if __name__=='__main__':
    main()