<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1606834916981" ID="ID_6874420" MODIFIED="1606919345592" STYLE="fork" TEXT="PersonalBudget">
<node CREATED="1606835007823" ID="ID_341455712" MODIFIED="1606919333999" POSITION="right" TEXT="1. Add income">
<node CREATED="1606835215809" ID="ID_408248260" MODIFIED="1606919333999" TEXT="Need to add vector/container of structs/objects">
<node CREATED="1606835254984" ID="ID_1635759664" MODIFIED="1606919333999" TEXT="This object need contain ">
<node CREATED="1606835311672" ID="ID_1494493295" MODIFIED="1606919333999" TEXT="Date"/>
<node CREATED="1606835317276" ID="ID_674180846" MODIFIED="1606919333999" TEXT="Float with expense"/>
<node CREATED="1606835325172" ID="ID_1710755883" MODIFIED="1606919333999" TEXT="User Id"/>
</node>
</node>
<node CREATED="1606835422590" ID="ID_1265757300" MODIFIED="1606919333999" TEXT="Need to save this in xml">
<node CREATED="1606835472420" ID="ID_1401511627" MODIFIED="1606919333999" TEXT="probably best template">
<node CREATED="1606835505595" ID="ID_875571374" MODIFIED="1606919333999" TEXT="ID/DATE/FLOAT">
<node CREATED="1606920187967" ID="ID_1233922235" MODIFIED="1606920196391" TEXT="FILE FORMAT">
<node CREATED="1606920201619" ID="ID_361631427" MODIFIED="1606934906813" TEXT="&lt;BUDGET&gt;">
<node CREATED="1606920218414" ID="ID_1040806894" MODIFIED="1606920471170" TEXT="&lt;USER, id&gt;">
<node CREATED="1606920259779" ID="ID_1145396296" MODIFIED="1606920503840" TEXT="&lt;INCOMES, incomes&gt;"/>
<node CREATED="1606920280483" ID="ID_1705591668" MODIFIED="1606920533199" TEXT="&lt;EXPENSES,expenses&gt;"/>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1606836630872" ID="ID_1672462726" MODIFIED="1606919333999" TEXT="Need to have function sorting dates">
<node CREATED="1606836655758" ID="ID_540634386" MODIFIED="1606919333999" TEXT="Probably best solution - ">
<node CREATED="1606836685235" ID="ID_1022430911" MODIFIED="1606919333999" TEXT="Lambda expressions"/>
<node CREATED="1606836703908" ID="ID_477859403" MODIFIED="1606919334000" TEXT=""/>
</node>
</node>
</node>
<node CREATED="1606835437071" ID="ID_326307841" MODIFIED="1606919334000" TEXT="Need to load previous"/>
</node>
<node CREATED="1606835038878" ID="ID_1961350776" MODIFIED="1606919334000" POSITION="right" TEXT="2.Add expense">
<node CREATED="1606835349625" ID="ID_319777035" MODIFIED="1606919334000" TEXT="It will be the same as incomes, just different vector">
<node CREATED="1606835377857" ID="ID_989883565" MODIFIED="1606919334000" TEXT="Probably via inheritance from base class(income/expense)"/>
</node>
</node>
<node CREATED="1606835055502" ID="ID_1416914607" MODIFIED="1606919334000" POSITION="right" TEXT="3.Balance for this month">
<node CREATED="1606835706047" ID="ID_1252244868" MODIFIED="1606919334000" TEXT="Need to have function checking today&apos;s date"/>
<node CREATED="1606835727424" ID="ID_1661946802" MODIFIED="1606919334000" TEXT="Need to have function showing expenses/incomes between 2 dates">
<node CREATED="1606835764586" ID="ID_784823415" MODIFIED="1606919334000" TEXT="Need to have function checking how many days have this month">
<node CREATED="1606835785239" ID="ID_222658531" MODIFIED="1606919334000" TEXT="Same problem as in 5. point">
<node CREATED="1606835799716" ID="ID_1795040627" MODIFIED="1606919334000" TEXT="Need to check year is leap or not"/>
</node>
</node>
</node>
</node>
<node CREATED="1606835116768" ID="ID_1796412573" MODIFIED="1606919334000" POSITION="right" TEXT="4. Balance for last month">
<node CREATED="1606835837935" ID="ID_754901824" MODIFIED="1606919334000" TEXT="Need to have function checking today&apos;s date"/>
<node CREATED="1606835852658" ID="ID_1265578980" MODIFIED="1606919334000" TEXT="showing balance between 2 dates">
<node CREATED="1606835871347" ID="ID_963781048" MODIFIED="1606919334000" TEXT="1. date will be 1 day of previous month"/>
<node CREATED="1606835896635" ID="ID_9732644" MODIFIED="1606919334000" TEXT="2. date will be last day of previous month">
<node CREATED="1606835912664" ID="ID_459334032" MODIFIED="1606919334000" TEXT="Need to have function checking how many days have this month"/>
</node>
</node>
</node>
<node CREATED="1606835125520" ID="ID_1412122858" MODIFIED="1606919334000" POSITION="right" TEXT="5.Balance for selected period">
<node CREATED="1606835545339" ID="ID_350726465" MODIFIED="1606919334000" TEXT="Need function checking if data was entered correctly">
<node CREATED="1606835591129" ID="ID_598083976" MODIFIED="1606919334000" TEXT="Need to check if year is above 2000"/>
<node CREATED="1606835602888" ID="ID_1885840418" MODIFIED="1606919334000" TEXT="Need to check if month is between 1-12"/>
<node CREATED="1606835617384" ID="ID_475090475" MODIFIED="1606919334000" TEXT="Need to check if day is correct">
<node CREATED="1606835627553" ID="ID_1022458680" MODIFIED="1606919334000" TEXT="Need to have function checking how many days have month"/>
<node CREATED="1606835660850" ID="ID_534939376" MODIFIED="1606919334000" TEXT="Need to have function checking if year is leap or not"/>
</node>
</node>
</node>
<node CREATED="1606835151855" ID="ID_1857863121" MODIFIED="1606919334000" POSITION="right" TEXT="6.Change password">
<node CREATED="1606835965196" ID="ID_546841163" MODIFIED="1606919334000" TEXT="Need to have function changing password in loaded container with users">
<node CREATED="1606835999990" ID="ID_374674588" MODIFIED="1606919334000" TEXT="Function saving changes (overwriting file with users data) "/>
</node>
</node>
<node CREATED="1606835166844" ID="ID_95593727" MODIFIED="1606919334000" POSITION="right" TEXT="7. Log out">
<node CREATED="1606836069163" ID="ID_1994046724" MODIFIED="1606919334000" TEXT="Dynamic memory (objects with incomes/expenses) deleted"/>
<node CREATED="1606836122751" ID="ID_284376665" MODIFIED="1606919334000" TEXT="change some variable contains id logged user into 0"/>
</node>
<node CREATED="1606835180331" ID="ID_145358084" MODIFIED="1606919334000" POSITION="left" TEXT="1A.Register">
<node CREATED="1606836523801" ID="ID_1554740141" MODIFIED="1606919334000" TEXT="Need to check if entered login already exist">
<node CREATED="1606836543140" ID="ID_1722129693" MODIFIED="1606919334000" TEXT="If not, ask for password">
<node CREATED="1606836553389" ID="ID_380541597" MODIFIED="1606919334000" TEXT="transform object into template">
<node CREATED="1606836580001" ID="ID_1854125659" MODIFIED="1606919334000" TEXT="Save template into file (xml or txt), just add">
<node CREATED="1606920315111" ID="ID_692938008" MODIFIED="1606920329431" TEXT="FILE FORMAT">
<node CREATED="1606920330611" ID="ID_1658187227" MODIFIED="1606920350534" TEXT="&lt;USERS&gt;">
<node CREATED="1606920365534" ID="ID_322222953" MODIFIED="1606920367181" TEXT="&lt;USER, login&gt;">
<node CREATED="1606920382031" ID="ID_351359133" MODIFIED="1606920383774" TEXT="&lt;PASSWORD, password&gt;"/>
<node CREATED="1606920384234" ID="ID_1365037983" MODIFIED="1606920400594" TEXT="&lt;ID,id&gt;"/>
</node>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1606837239679" ID="ID_1115589058" MODIFIED="1606919334000" TEXT="function checking if login exists, best with iterator"/>
</node>
<node CREATED="1606837214457" ID="ID_1762495935" MODIFIED="1606919334000" TEXT="Need class with container"/>
</node>
<node CREATED="1606835192332" ID="ID_1404539042" MODIFIED="1606919334000" POSITION="left" TEXT="2A. Log in">
<node CREATED="1606837183524" ID="ID_370658136" MODIFIED="1606919334000" TEXT="Check if entered login exist">
<node CREATED="1606837194671" ID="ID_538642469" MODIFIED="1606919334000" TEXT="If yes, check the password"/>
<node CREATED="1606837266570" ID="ID_1104842371" MODIFIED="1606919334000" TEXT="As above, function with iterator"/>
</node>
</node>
<node CREATED="1606835198205" ID="ID_1411679153" MODIFIED="1606919334000" POSITION="left" TEXT="3A. Close program"/>
</node>
</map>
