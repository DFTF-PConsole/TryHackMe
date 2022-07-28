# THM - Crack The Hash Level 2

```shell
haiti 741ebf5166b9ece4cca88a3868c44871e8370707cf19af3ceaa4a6fba006f224ae03f39153492853

haiti 1aec7a56aa08b25b596057e1ccbcb6d768b770eaa0f355ccbd56aee5040e02ee

python3 ./wordlistctl.py search rockyou

python3 ./wordlistctl.py search -h

python3 ./wordlistctl.py fetch -l rockyou

python3 ./wordlistctl.py search -l rockyou

python3 ./wordlistctl.py fetch -l rockyou -d

python3 ./wordlistctl.py search facebook

python3 ./wordlistctl.py list -g usernames


john hash.txt --wordlist=/usr/share/wordlists/passwords/rockyou.txt rules=norajCommon02
```

/etc/john/

```shell
sudo nano /etc/john/john-local.conf

sudo nano /etc/john/john.conf

sudo nano /usr/share/john/john-local.conf

john hash.txt --format=raw-sha1 --wordlist=../../Materials/SecLists/Passwords/Common-Credentials/10k-most-common.txt --rules=THM01


python3 ./wordlistctl.py fetch -l dogs -d fetch_term

cp /usr/share/wordlists/misc/dogs.txt dogs.txt


sudo apt install python3-setuptools python3-tk
git clone https://github.com/sc0tfree/mentalist
cd mentalist/
sudo python3 setup.py install


mentalist

haiti ed91365105bba79fdab20c376d83d752

john hash.txt --format=raw-md5 --wordlist=dogs-mentalist.txt


cewl -d 2 -w example.txt https://example.org


ttpassgen --rule '[?d]{4:4:*}' pin.txt

ttpassgen --rule '[?l]{1:3:*}' abc.txt

ttpassgen --dictlist 'pin.txt,abc.txt' --rule '$0[-]{1}$1' combination.txt

haiti e5b47b7e8df2597077e703c76ee86aee

john hash.txt --format=raw-md5 --wordlist=combination.txt


haiti b16f211a8ad7f97778e5006c7cecdf31
echo "b16f211a8ad7f97778e5006c7cecdf31" > hash.txt
python3 ./wordlistctl/wordlistctl.py search malenames 
sudo python3 ./wordlistctl/wordlistctl.py fetch -l top_1000_usa_malenames_english -d fetch_term
cp /usr/share/wordlists/misc/top_1000_usa_malenames_english.txt top_1000_usa_malenames_english.txt
john hash.txt --format=raw-md5 --wordlist=top_1000_usa_malenames_english.txt --rules=norajCommon02


haiti 7463fcb720de92803d179e7f83070f97
echo "7463fcb720de92803d179e7f83070f97" > hash.txt
python3 ./wordlistctl/wordlistctl.py search female 
sudo python3 ./wordlistctl/wordlistctl.py fetch -l top_1000_usa_femalenames_english -d fetch_term
cp /usr/share/wordlists/misc/top_1000_usa_femalenames_english.txt top_1000_usa_femalenames_english.txt
john hash.txt --format=raw-md5 --wordlist=top_1000_usa_femalenames_english.txt --rules=norajCommon01


haiti f4476669333651be5b37ec6d81ef526f
echo "f4476669333651be5b37ec6d81ef526f" > hash.txt
python3 ./wordlistctl/wordlistctl.py search city
sudo python3 ./wordlistctl/wordlistctl.py fetch -l city-state-country -d fetch_term
cp /usr/share/wordlists/misc/city-state-country.txt city-state-country.txt
cat city-state-country.txt | dos2unix | rg 'Mexico$' | cut -f 1 -d ',' | uniq > mexico.txt
mentalist
john hash.txt --format=raw-md5 --wordlist=mexico-mentalist2.txt
john hash.txt --format=raw-md5 --wordlist=mexico-mentalist3.txt
john hash.txt --format=raw-md5 --wordlist=mexico-mentalist4.txt
john hash.txt --format=raw-md5 --wordlist=mexico-mentalist5.txt
john hash.txt --format=raw-md5 --wordlist=mexico.txt --rules=l33t

john --show --format=raw-md5 hash.txt


haiti a3a321e1c246c773177363200a6c0466a5030afc
echo "a3a321e1c246c773177363200a6c0466a5030afc" > hash.txt
john hash.txt --format=raw-sha1 --wordlist=david.txt --rules=NT


haiti d5e085772469d544a447bc8250890949
echo "d5e085772469d544a447bc8250890949" > hash.txt
python3 ./lyricpass/lyricpass.py -a adele
cat raw-lyrics-2022-04-13-00.54.01 > adele.txt
john hash.txt --format=raw-md5 --wordlist=adele.txt --rules=norajCommon03


haiti 377081d69d23759c5946a95d1b757adc
echo "377081d69d23759c5946a95d1b757adc" > hash.txt
git clone https://github.com/toxydose/pnwgen
nano pnwgen/prefix.txt	# +1721 Sint Maarten
python3 ./pnwgen/pnwgen.py +1721 '' 7
cp wordlist.txt numberphone.txt
john hash.txt --format=raw-md5 --wordlist=numberphone.txt


haiti ba6e8f9cd4140ac8b8d2bf96c9acd2fb58c0827d556b78e331d1113fcbfe425ca9299fe917f6015978f7e1644382d1ea45fd581aed6298acde2fa01e7d83cdbd
echo "ba6e8f9cd4140ac8b8d2bf96c9acd2fb58c0827d556b78e331d1113fcbfe425ca9299fe917f6015978f7e1644382d1ea45fd581aed6298acde2fa01e7d83cdbd" > hash.txt
john hash.txt --format=raw-sha3 --wordlist=../../Materials/KaliWordlists/rockyou.txt


haiti 9f7376709d3fe09b389a27876834a13c6f275ed9a806d4c8df78f0ce1aad8fb343316133e810096e0999eaf1d2bca37c336e1b7726b213e001333d636e896617
echo "9f7376709d3fe09b389a27876834a13c6f275ed9a806d4c8df78f0ce1aad8fb343316133e810096e0999eaf1d2bca37c336e1b7726b213e001333d636e896617" > hash.txt
cewl -d 2 -w website.txt http://10.10.113.252/rtfm.re/en/sponsors/index.html
john hash.txt --format=Raw-Blake2 --wordlist=website.txt --rules=norajCommon04


haiti $6$kI6VJ0a31.SNRsLR$Wk30X8w8iEC2FpasTo0Z5U7wke0TpfbDtSwayrNebqKjYWC4gjKoNEJxO/DkP.YFTLVFirQ5PEh4glQIHuKfA/
echo "$6$kI6VJ0a31.SNRsLR$Wk30X8w8iEC2FpasTo0Z5U7wke0TpfbDtSwayrNebqKjYWC4gjKoNEJxO/DkP.YFTLVFirQ5PEh4glQIHuKfA/" > hash.txt
john hash.txt --format=sha512crypt --wordlist=../../Materials/KaliWordlists/rockyou.txt
```

