#include <LiquidCrystal.h>
#include <Flash.h>

#define AWESOME_NAME_LENGTH 108
#define NAMES_LENGTH 574

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin = 1;

int ctr;
int buttonState = 1;
char firstName[17];
char lastName[17];
char name[34];    

void setup() {
  pinMode(buttonPin, INPUT);     
  ctr = 0;
  randomSeed(analogRead(0));

  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print(" Initializing");
  lcd.setCursor(0, 1);
  lcd.print("  Imagination");

  delay(2000);

  lcd.setCursor(0, 0);
  lcd.print("Press the button");
  lcd.setCursor(0, 1);
  lcd.print("  to find a name.");
  
  randomSeed(random(0,1000) * analogRead(0));
}

void loop() {
  /*Need to add Virginia Creeper, Tawny Frogmouth, Blewit, Compressed Flapwort, Screaming Hairyarmadillo, Cheese Weed, Dragon Hunter, Hell Bender, Bat Falcon, Centauri, Mother OfThousands*/
  FLASH_STRING_ARRAY(awesomeNames, PSTR("Moon Unit"),PSTR("Dweezel G"),
      PSTR("Gloves Ofmetal"), PSTR("Airwrecka Brie"), PSTR("Barenuckle GorillaPunch"), PSTR("L'monjello powder"), PSTR("Mustafa Wolfgang"), PSTR("Wolfgang Maximus "),  PSTR("Yngwie Malmsteen"), PSTR("Roscoe Toboscoe"), PSTR("Arnold Schwarzenegger"),
      PSTR("Neia Bobilla"), PSTR("Skunk Ahdjunk"), PSTR("T'varisuness King"), PSTR("Tyroil Smoochie-Wallace"), PSTR("D'Squarius Green"), PSTR("Jackmerius Tacktheritrix"), PSTR("Shaft Undertaker"), PSTR("Davoin Shower-Handel"), 
      PSTR("Hingle McCringleberry"), PSTR("L'Carpetron Dookmarriot"), PSTR("J'Dinkalage Morgoone"), PSTR("Saggitariutt Jefferspin"), PSTR("D'Glester Hardunkichud"), PSTR("Swirvithan L'Goodling-Splat"), PSTR("Quatro Quatro"),
      PSTR("Ozamataz Buckshank"), PSTR("Beezer Washingbeard"), PSTR("Sequester Grundelplith"), PSTR("Velociraptor Maloish"), PSTR("Donkey Teeth"), PSTR("Bon'quisha Barbisha"), PSTR("Black Dynamite"), PSTR("Brikwilla Shorilla"),
      PSTR("Charro Chevelle"), PSTR("Lester Wigeon"), PSTR("Gabriel O'hannan"), PSTR("Shirwode Paris"), PSTR("McArthur Scurlock"), PSTR("Meriwether Huleatt"), PSTR("Algernon Bolan"), PSTR("Lazuli Oddlin"), PSTR("Horace Ra"), PSTR("Sterling Wheelagan"),
      PSTR("Maximillian Chamberlin"), PSTR("Sharktooth Chompenstein"), PSTR("Linus Magnus"), PSTR("Declan Broderick"), PSTR("Farringdon Goldenplover"), PSTR("Kipling Wellington"), PSTR("Thor Gunner"), PSTR("Aegus Banyu"), PSTR("Ovond Dalumma"),
      PSTR("Haala Naljak"), PSTR("Kilni Barmalk"), PSTR("Vulcan Firepants"), PSTR("Perseus Draco"), PSTR("Calypso Achilles"), PSTR("Draker Finn"), PSTR("Poseidon Kronus"), PSTR("Bacchus Provan"), PSTR("Santiago Persulfate"), PSTR("Electra Bunny"),
      PSTR("Thesius Glutimus"), PSTR("Dee-ann Decadence"), PSTR("Panther Lewis"), PSTR("Rex Yokar"), PSTR("Vehement Chaos"), PSTR("Flesh Sphere"), PSTR("Vengeful Terror"), PSTR("Haunted Throne"), PSTR("Steel Lord"), PSTR("Nordic Flames"),
      PSTR("Midwinter Slimecloud"), PSTR("Striker Onyx"), PSTR("Stormy Midori"), PSTR("Iron Carnage"), PSTR("Holy Slayer"), PSTR("Astral Oath"), PSTR("Nuclear Flesh"), PSTR("Ax Blaze"), PSTR("Max Power"), PSTR("Moon java"), PSTR("Astral Plane"), PSTR("Balbo Shrooms"),
      PSTR("Bebo Suncloud"), PSTR("Clover Deva"), PSTR("Mary Juwanta"), PSTR("Moon Moon"), PSTR("Wolfsong SingingHawk"), PSTR("Seagull Dream"), PSTR("Gordon Fisherman"), PSTR("Doobie Marygold"), PSTR("Magnolia Sunburst"), PSTR("Cheeseburger Combo"),
      PSTR("Bohemian Baybieneim"), PSTR("Waverly Piper"), PSTR("Gideon Lawson"), PSTR("Winter Lark"), PSTR("Venus Frost"), PSTR("Hungry Sealion"), PSTR("Blade Armageddon"), PSTR("Ronald Reagan"), PSTR("Tiberius Wreckinball"), PSTR("Sampson Scarface"),
      PSTR("Orthidonticus Mouthyface"), PSTR("Mantis Shrimp"), PSTR("Hyper Dontia"));
  
  FLASH_STRING_ARRAY(names, 
      PSTR("Aariyah"), PSTR("Aayana"), PSTR("Abdulrahim"), PSTR("Aburrow"), PSTR("Acelyn"), PSTR("Adali"), PSTR("Adamik"), PSTR("Adewale"), PSTR("Aerica"), PSTR("Aily"), PSTR("Akeel"), PSTR("Alahna"), PSTR("Alaila"), PSTR("Aleitha"), PSTR("Aleki"), PSTR("Alekzander"), PSTR("Alera"), PSTR("Alexanne"), PSTR("Algeria"), PSTR("Algore"), PSTR("Aliceia"), PSTR("Alixandra"), PSTR("Allchorn"), PSTR("Alsopp"), PSTR("Alkins"), PSTR("Amontay"), PSTR("Amyas"), PSTR("Anaalicia"), PSTR("Anara"), PSTR("Anglie"), PSTR("Anindita"), PSTR("Ansett"), PSTR("Antaniya"), PSTR("Antuk"), PSTR("Arbor"), PSTR("Armatidge"), PSTR("Arthas"), PSTR("Ashmi"), PSTR("Astrid"), PSTR("Attikus"), PSTR("Attril"), PSTR("Attwood"), PSTR("Aurthur"), PSTR("Aver"), PSTR("Avry"), PSTR("Awty"), PSTR("Aydelis"), PSTR("Aydrien"), PSTR("Ayunna"), PSTR("Azelin"), PSTR("Ballingal"), PSTR("Balmann"), PSTR("Baretta"), PSTR("Baudts"), PSTR("Beese"), PSTR("Benardette"), PSTR("Benjeman"), PSTR("Berlinda"), PSTR("Besim"), PSTR("Besset"), PSTR("Bettyjo"), PSTR("Bevelyn"), PSTR("Bezawit"), PSTR("Bhar"), PSTR("Bickardike"), PSTR("Bilsland"), PSTR("Black"), PSTR("Boneta"), PSTR("Boog"), PSTR("Bouts"), PSTR("Bradnon"), PSTR("Braisher"), PSTR("Branesha"), PSTR("Bransford"), PSTR("Breneshia"), PSTR("Brete"), PSTR("Brialle"), PSTR("Briane"), PSTR("Brimner"), PSTR("Brindin"), PSTR("Broedy"), PSTR("Bronsyn"), PSTR("Brookeann"), PSTR("Brunning"), PSTR("Buchan"), PSTR("Bulcock"), PSTR("Burridge"), PSTR("Callister"), PSTR("Cambrea"), PSTR("Cameren"), PSTR("Careswell"), PSTR("Cargill"), PSTR("Castin"), PSTR("Catherall"), PSTR("Caughey"), PSTR("Cavan"), PSTR("Cessily"), PSTR("Chakakhan"), PSTR("Chandal"), PSTR("Chantol"), PSTR("Chara"), PSTR("Chea"), PSTR("Chejuana"), PSTR("Chelcee"), PSTR("Chella"), PSTR("Cheson"), PSTR("Chessa"), PSTR("Chezier"), PSTR("Chineye"), PSTR("Christieann"), PSTR("Chyenne"), PSTR("Clementel"), PSTR("Coles"), PSTR("Condie"), PSTR("Conita"), PSTR("Conneely"), PSTR("Cooney"), PSTR("Corah"), PSTR("Cordario"), PSTR("Cowper"), PSTR("Creston"), PSTR("Critoph"), PSTR("Croutear"), PSTR("Cunnell"), PSTR("Cuppleditch"), PSTR("Cuvley"), PSTR("Daisye"), PSTR("Dang"), PSTR("Daphnie"), PSTR("De Najera"), PSTR("Deiondre"), PSTR("Delacey"), PSTR("Delise"), PSTR("Dellenbach"), PSTR("Demoge"), PSTR("Dennishia"), PSTR("Deshanti"), PSTR("Devendra"), PSTR("Dewana"), PSTR("Dewar"), PSTR("Deyshaun"), PSTR("Dianca"), PSTR("Dilen"), PSTR("Dillet"), PSTR("Diss"), PSTR("Diyor"), PSTR("Dnae"), PSTR("Dodell"), PSTR("Dooler"), PSTR("Dorell"), PSTR("Dorr"), PSTR("Dresha"), PSTR("Duck"), PSTR("Dugall"), PSTR("Durden"), PSTR("Earldene"), PSTR("Eatock"), PSTR("Edison"), PSTR("Edith"), PSTR("Edvard"), PSTR("Eiichi"), PSTR("Eliab"), PSTR("Elizabete"), PSTR("Elley"), PSTR("Elmira"), PSTR("Elyas"), PSTR("Elziabeth"), PSTR("Emari"), PSTR("Erblin"), PSTR("Ervey"), PSTR("Eual"), PSTR("Evaine"), PSTR("Evemarie"), PSTR("Exum"), PSTR("Farlane"), PSTR("Farr"), PSTR("Fasler"), PSTR("Fautley"), PSTR("Feeney"), PSTR("Fish"), PSTR("Flabio"), PSTR("Flo"), PSTR("Flormaria"), PSTR("Franccesca"), PSTR("Gaetano"), PSTR("Gaelan"), PSTR("Garnall"), PSTR("Garrigan"), PSTR("Gavina"), PSTR("Gaylyn"), PSTR("Genera"), PSTR("Gentric"), PSTR("Geogory"), PSTR("Giacoppo"), PSTR("Giannotti"), PSTR("Gingold"), PSTR("Goldsmith"), PSTR("Gostridge"), PSTR("Gregrey"), PSTR("Gumery"), PSTR("Hairo"), PSTR("Hambright"), PSTR("Hargis"), PSTR("Harlynn"), PSTR("Harrhy"), PSTR("Haseman"), PSTR("Hatti"), PSTR("Haycox"), PSTR("Heatly"), PSTR("Hennah"), PSTR("Hosby"), PSTR("Hoscar"), PSTR("Hurich"), PSTR("Imena"), PSTR("Indalecio"), PSTR("Ireal"), PSTR("Itzik"), PSTR("Ivagene"), PSTR("Iyani"), PSTR("Izuchukwu"), PSTR("Jabus"), PSTR("Jackielyn"), PSTR("Jacqlynn"), PSTR("Jahn"), PSTR("Jaileigh"), PSTR("Jakobey"), PSTR("Jakobssen"), PSTR("Jaksen"), PSTR("Jamelia"), PSTR("Janelee"), PSTR("Jannine"), PSTR("Jaquaisha"), PSTR("Jarell"), PSTR("Jasmyne"), PSTR("Jawon"), PSTR("Jaymi"), PSTR("Jazzalynn"), PSTR("Jeaneth"), PSTR("Jedrych"), PSTR("Jeeva"), PSTR("Jenci"), PSTR("Jeniene"), PSTR("Jeniya"), PSTR("Jeramia"), PSTR("Jerrina"), PSTR("Jeune"), PSTR("Jihan"), PSTR("Jonquil"), PSTR("Jonquin"), PSTR("Josehua"), PSTR("Josue"), PSTR("Julis"), PSTR("Jullie"), PSTR("Julynn"), PSTR("Jwuan"), PSTR("Kable"), PSTR("Kahlilah"), PSTR("Kaiana"), PSTR("Kailea"), PSTR("Kaine"), PSTR("Kaisey"), PSTR("Kalayah"), PSTR("Kanalu"), PSTR("Kaname"), PSTR("Karalyne"), PSTR("Kawaiola"), PSTR("Kaydan"), PSTR("Kayl"), PSTR("Keddie"), PSTR("Kehly"), PSTR("Kelcey"), PSTR("Kelcy"), PSTR("Kennham"), PSTR("Kenyada"), PSTR("Kenze"), PSTR("Keppy"), PSTR("Keriona"), PSTR("Khalila"), PSTR("Khandra"), PSTR("Killian"), PSTR("Kilolo"), PSTR("Kio"), PSTR("Kirklyn"), PSTR("Kittie"), PSTR("Kleinpeltz"), PSTR("Knappen"), PSTR("Kourtnee"), PSTR("Krishana"), PSTR("Kyleemarie"), PSTR("Kyneisha"), PSTR("Labadini"), PSTR("Laborn"), PSTR("Lachana"), PSTR("Lacheze"), PSTR("Lambot"), PSTR("Lamiya"), PSTR("Landan"), PSTR("Laniece"), PSTR("Laquavia"), PSTR("Latausha"), PSTR("Latefia"), PSTR("Laureat"), PSTR("Lavale"), PSTR("Laxe"), PSTR("Layci"), PSTR("Le Maitre"), PSTR("Leatherborrow"), PSTR("Lenoxx"), PSTR("Leoler"), PSTR("Leosha"), PSTR("Lestat"), PSTR("Leyonna"), PSTR("Liah"), PSTR("Licciardiello"), PSTR("Lillianrose"), PSTR("Lissbet"), PSTR("Livings"), PSTR("Loc"), PSTR("Lomaz"), PSTR("Lon"), PSTR("Lonza"), PSTR("Lorilyn"), PSTR("Lovelady"), PSTR("Ludell"), PSTR("Lillette"), PSTR("Ludwika"), PSTR("Lui"), PSTR("Lukovic"), PSTR("Lundynn"), PSTR("Lutrecia"), PSTR("Luzmary"), PSTR("Lylian"), PSTR("Mableson"), PSTR("Mabon"), PSTR("MacDermott"), PSTR("MacPhail"), PSTR("Macauly"), PSTR("Mahlon"), PSTR("Mahogony"), PSTR("Malachai"), PSTR("Maray"), PSTR("Margherite"), PSTR("Margory"), PSTR("Maricka"), PSTR("Maris"), PSTR("Markavius"), PSTR("Markevius"), PSTR("Madilyn"), PSTR("Marreco"), PSTR("Mayford"), PSTR("McCorkindale"), PSTR("McErlaine"), PSTR("McGonigle"), PSTR("McNeilley"), PSTR("McNiven"), PSTR("Mcauthur"), PSTR("Mckaylen"), PSTR("Media"), PSTR("Meghana"), PSTR("Menelaws"), PSTR("Merrington"), PSTR("Masako"), PSTR("Miarah"), PSTR("Michiko"), PSTR("Miecislaus"), PSTR("Miere"), PSTR("Miklos"), PSTR("Milanie"), PSTR("Minchell"), PSTR("Minguet"), PSTR("Mitzy"), PSTR("Moena"), PSTR("Moorhead"), PSTR("Morcombe"), PSTR("Morfey"), PSTR("Muzammil"), PSTR("Mystik"), PSTR("Naiyah"), PSTR("Nanelli"), PSTR("Natesha"), PSTR("Naul"), PSTR("Navayah"), PSTR("Ncole"), PSTR("Neem"), PSTR("Nelvina"), PSTR("Newgrosh"), PSTR("Nickita"), PSTR("Nicteha"), PSTR("Niema"), PSTR("Nilah"), PSTR("Nino"), PSTR("Noehly"), PSTR("Norma"), PSTR("Northa"), PSTR("Novalee"), PSTR("Nuvia"), PSTR("Nyeasia"), PSTR("Nyjia"), PSTR("Nyveah"), PSTR("O'Scandall"), PSTR("Olivama"), PSTR("Olumide"), PSTR("Olla"), PSTR("Omarri"), PSTR("Ousbie"), PSTR("Paizlee"), PSTR("Pancho"), PSTR("Pardon"), PSTR("Pasmore"), PSTR("Patrell"), PSTR("Paulla"), PSTR("Peppin"), PSTR("Permelia"), PSTR("Perrycost"), PSTR("Peteris"), PSTR("Philander"), PSTR("Philipp"), PSTR("Piche"), PSTR("Pierri"), PSTR("Pioquinto"), PSTR("Prandin"), PSTR("Pucker"), PSTR("Qualiyah"), PSTR("Quanesia"), PSTR("Quanette"), PSTR("Quanishia"), PSTR("Quientin"), PSTR("Quinby"), PSTR("Quinn"), PSTR("Quintasha"), PSTR("Raidel"), PSTR("Ramas"), PSTR("Ramsted"), PSTR("Randall"), PSTR("Randleson"), PSTR("Rchel"), PSTR("Read"), PSTR("Reg"), PSTR("Rehan"), PSTR("Rentilll"), PSTR("Rhyson"), PSTR("Richard"), PSTR("Ridhi"), PSTR("Rocks"), PSTR("Roddan"), PSTR("Rodger"), PSTR("Roget"), PSTR("Rohlf"), PSTR("Rolles"), PSTR("Rostern"), PSTR("Roschell"), PSTR("Rotimi"), PSTR("Rottery"), PSTR("Ruot"), PSTR("Rutvi"), PSTR("Saamya"), PSTR("Sacoria"), PSTR("Safi"), PSTR("Sakhia"), PSTR("Sarahjean"), PSTR("Saraiya"), PSTR("Saurabh"), PSTR("Schnell"), PSTR("Schwandt"), PSTR("Sclater"), PSTR("Seally"), PSTR("Seiry"), PSTR("Serman"), PSTR("Sevannah"), PSTR("Seynabou"), PSTR("Shad"), PSTR("Shadeen"), PSTR("Shaleese"), PSTR("Shaquan"), PSTR("Shaquanta"), PSTR("Shatel"), PSTR("Shaundale"), PSTR("Shauntea"), PSTR("Shawnese"), PSTR("Shawntane"), PSTR("Shayanne"), PSTR("Sherbrooke"), PSTR("Shermane"), PSTR("Shouana"), PSTR("Showen"), PSTR("Sibbet"), PSTR("Sigvard"), PSTR("Silena"), PSTR("Smorthwaite"), PSTR("Snellman"), PSTR("Soffe"), PSTR("Someeka"), PSTR("Souza"), PSTR("Srihan"), PSTR("Sstephanie"), PSTR("Staint Aubyn"), PSTR("Stead"), PSTR("Stedmond"), PSTR("Stirgess"), PSTR("Stokell"), PSTR("Stollsteiner"), PSTR("Strelitzer"), PSTR("Strete"), PSTR("Strotton"), PSTR("Stuckey"), PSTR("Sunday"), PSTR("Suyai"), PSTR("Suzane"), PSTR("Swann"), PSTR("Syndia"), PSTR("Tailah"), PSTR("Taim"), PSTR("Taiwon"), PSTR("Tajir"), PSTR("Takahiro"), PSTR("Takira"), PSTR("Talaysha"), PSTR("Tallquist"), PSTR("Tannin"), PSTR("Tammey"), PSTR("Taranisha"), PSTR("Tenicia"), PSTR("Terius"), PSTR("Terrayne"), PSTR("Teyha"), PSTR("Thrisa"), PSTR("Tideswell"), PSTR("Tinnelle"), PSTR("Tisean"), PSTR("Tomoaki"), PSTR("Tonja"), PSTR("Trayes"), PSTR("Treydon"), PSTR("Trishonda"), PSTR("Tryton"), PSTR("Tudhope"), PSTR("Tutchings"), PSTR("Tyleik"), PSTR("Tymirah"), PSTR("Tymon"), PSTR("Tyres"), PSTR("Tyress"), PSTR("Tyronn"), PSTR("Ulus"), PSTR("Urmi"), PSTR("Vachel"), PSTR("Van der Vlies"), PSTR("Vasilevich"), PSTR("Vivians"), PSTR("Waddington"), PSTR("Wayde"), PSTR("Wealthall"), PSTR("Wear"), PSTR("Welford"), PSTR("Whitty"), PSTR("Whotton"), PSTR("Widdup"), PSTR("Wiletta"), PSTR("Wimpenny"), PSTR("Woodthorpe"), PSTR("Wordie"), PSTR("Worland"), PSTR("Worton"), PSTR("Wyndee"), PSTR("Yancarlo"), PSTR("Yancy"), PSTR("Yna"), PSTR("Yon"), PSTR("Zacharry"), PSTR("Zahaira"), PSTR("Ziemke"), PSTR("Zygmund"), PSTR("Zeplin"), PSTR("Zekira"), 
  );
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == 0)
  {
    //Reset the name buffers to spaces
    for(int x = 0; x<34; x++)
    {
      name[x] = ' ';
    }
    for(int x = 0; x < 17; x++)  
    {
      lastName[x] = ' ';
      firstName[x] = ' ';
    }
 
    int i;
    unsigned int found = 0;
 
    //the first 4 names should come from the list of awesome names         
    if (ctr < 4)
    {
      ctr++;
      i = random(0, AWESOME_NAME_LENGTH);
      awesomeNames[i].copy(name, 34);
    
      for(int x = 0; x <= 33; x++)
      {
        if (name[x] == ' ')
        {
          found = x;
          firstName[x] = '\0';
          x++;
        }
        if (found == 0)
        {
          firstName[x] = name[x];
        }
        else
        {
          lastName[x-found-1] = name[x];
          if (name[x] ==' ' || name[x] == '\0') x = 34;
        }
      }
    }
    else
    {
      if(random(100) <= 25)
      {
        i = random(0, AWESOME_NAME_LENGTH);
        awesomeNames[i].copy(name, 34);
        found = 0;
        for(int x = 0; x <= 33; x++)
        {
          if (name[x] == ' ')
          {
            firstName[x] = '\0';
            found = x;
            x++;
          }
          if (found == 0)
          {
            firstName[x] = name[x];
          }
        }
        
        i = random(0, AWESOME_NAME_LENGTH);
        awesomeNames[i].copy(name, 34);
        
        found = 0;
        for(int x = 0; x <= 33; x++)
        {
          if (name[x] == ' ')
          {
            found = x;
            x++;
          }
          if (found != 0)
          {
            lastName[x-found-1] = name[x];
            if (name[x] ==' ' || name[x] == '\0') x = 34;
          }
        }
      }
      else
      {
        i = random(0, NAMES_LENGTH);
        names[i].copy(firstName, 16);

        i = random(0, NAMES_LENGTH);
        names[i].copy(lastName, 16);

      }
    }
    
    AnimateDisplay('*', firstName, lastName);
  }
}

void AnimateDisplay(char placeHolder, char* line1, char* line2)
{
  char buf1[16];
  char buf2[16];
  char centered1[16];
  char centered2[16];
  
  for(int i = 0; i < 16; i++)
  {
    buf1[i] = placeHolder;
    buf2[i] = placeHolder;
    centered1[i] = ' ';
    centered2[i] = ' ';
  
  }
  
  int len1 = 0;
  int len2 = 0;
  while((byte)line1[len1] != 0) len1++;
  while((byte)line2[len2] != 0) len2++;  

  len1++;len2++;

  for(int i = 0; i < len1; i++)
  {
    centered1[((16-len1)/2) + i] = line1[i];    
  }
  centered1[15] = '\0';
  
  for(int i = 0; i < len2; i++)
  {
    centered2[((16-len2)/2) + i] = line2[i];    
  }
  centered2[15] = '\0';
  
  //Animate the shrinking placeholders
  for(int i = 0; i < 8; i++)
  {
    lcd.clear();  
    lcd.print(buf1);
    lcd.setCursor(0,1);
    lcd.print(buf2);
    buf1[i] = ' ';
    buf1[15-i] = ' ';
    buf2[i] = ' ';
    buf2[15-i] = ' ';
    delay(100);
  }
  
  //Display the centered name
  lcd.clear();
  lcd.print(centered1);
  lcd.setCursor(0,1);
  lcd.print(centered2);
}

