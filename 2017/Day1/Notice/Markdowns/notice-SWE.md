# Att beakta

Varje uppgift har ett bifogat paket som finns tillgängligt både i CMS och på ditt skrivbord.

För "uteslutande utdata"-uppgifter:
* Paketet innehåller testfall och exempeltestfall. Varje testfall är ett separat delproblem.
* Du får skicka in många filer i en enda zip-fil. Namnge då filerna `??.out`, där `??` är testfallsnumret (t.ex. `03.out`). Du kan zippa många filer med kommandot: `zip output.zip *.out`
* Du får göra upp till 100 inskickningar på uteslutande utdata-uppgifter. I varje inskickning får du inkludera utdatafiler för godtycklig delmängd av testfallen.

För andra uppgifter:
* Paketet innehåller exempeldomare, exempelimplementationer, exempeltestfall och kompileringsskript.
* Du måste skicka in exakt en fil, och du får göra upp till 50 inskickningar.
* Dina inskickningar får inte läsa från standard input, skriva till standard output eller interagera någon annan fil. Du får dock skriva till standard error.
* Namnet på filen du ska skicka in är givet i problemlydelsens sidhuvud (till höger). Den ska implementera proceduren som beskrivs i problemlydelsen och använda sig av de signaturer som ges i exempelimplementationen.
* Du får implementera andra procedurer.
* När du testar ditt program med exempeldomaren måste din indata följa de format och gränser som ges i problemlydelse, annars kan vad som helst hända.

## Konventioner

Problemlydelserna specifierar signaturer med de generiska typnamnen  `bool`, `integer`, `int64`, och `int[]` (array).

I alla de programmeringsspråk som domaren stödjer används lämpliga datatyper eller implementationer enligt tabellen nedan:

Språk | `bool` | `integer` | `int64` |  `int[]` | längd av array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Gränser

Problem | Tidsgräns | Minnesgräns
--- | --- | ---
nowruz | Uteslutande utdata | Uteslutande utdata
wiring | 1 s | 256 MB
train | 2 s | 256 MB
