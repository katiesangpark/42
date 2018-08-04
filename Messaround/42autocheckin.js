var Places;
var tenmin;
var twosec;
var continueCountdown;
var i;
var current;
var currentID;
var currentDate;
var TurboText;
var turboButton;
var RightNow;
var LastAudioExec;

function RefreshPage() {
    	location.reload(true);
}

function SetBlack(element) {
	element.style.color = "black";
}

function random(div) {
	return (Math.random(5, 10) * 10) / div;
}

function getCookieValue(cookieName){
	var startPos;
	var endPos;
	
	startPos = document.cookie.indexOf(cookieName + "=");
	
	if(startPos == -1)
		return "";
	
	startPos += cookieName.length + 1;
	endPos = document.cookie.substring(startPos).indexOf(";");
	return (endPos == -1) ? (document.cookie.substring(startPos)) : (document.cookie.substring(startPos, endPos + startPos));
}

function Countdown(number) {
    if (number > 0.0 && continueCountdown) {
		turboButton.innerText = TurboText + " (" + parseInt(number) + "s)";
		setTimeout(Countdown, number > 0 ? 105 : number, number - 0.1);
	}
	else if (continueCountdown) 
		RefreshPage();
}

function Turbo() {
	if (getCookieValue("turbo") === "") 
		document.cookie = "turbo=1";
	else
		document.cookie = "turbo=0;expires=" + RightNow;
	RefreshPage();
}

function RemoveAlert() {
	document.cookie = "playsound=0;expires=" + RightNow;
	document.cookie = "alert=0;expires=" + RightNow;
	RefreshPage();
}

function stopCountdown() {
	continueCountdown = false;
	turboButton.innerText = TurboText;
}

function getElementIndex(node) {
    var index;
	
	index = 0;
    while ((node = node.previousElementSibling)) {
        index++;
    }
    return index;
}

function PlayAudio(URL, volume = 1.0) {
	if (new Date() - LastAudioExec < 1500) {
		setTimeout(PlayAudio, 1500, URL, volume);
		return ;
	}
	LastAudioExec = new Date();
	var audio;
	audio = new Audio(URL);
	audio.volume = volume;
	audio.play();
}

function StopRefresh() {
	if (getCookieValue("stopRefresh") !== "1") {
		document.cookie = "stopRefresh=1";
		document.querySelector("#refresh").innerText = "Start refresh";
		stopCountdown();
	}
	else {
		document.cookie = "stopRefresh=0;expires=" + RightNow;
		RefreshPage();
	}
}

function ManualCheckin() {
	if (getCookieValue("manualCheckin") !== "1") {
		document.cookie = "manualCheckin=1";
		document.querySelector("#checkinManual").innerText = "Manual (enabled)";
	}
	else {
		document.cookie = "manualCheckin=0;expires=" + RightNow;
		document.querySelector("#checkinManual").innerText = "Automatic (enabled)";
	}
}


function Init() {	
	var arr;
	
	Places 				= document.querySelectorAll(".span12 table.table-hover tr td:nth-child(2)");
	current 			= document.querySelector("table .btn.btn-primary").parentElement.parentElement;
	currentDate 		= current.querySelector("td:nth-child(1)").innerText;
	arr 				= [];
	tenmin 				= new Date();
	LastAudioExec		= new Date();
	twosec 				= new Date();
	RightNow 			= new Date();
	twosec.setTime(twosec.getTime() + (2000));
	RightNow.setTime(RightNow.getTime() - (2000));
	tenmin.setTime(tenmin.getTime() + (60000 * 30));
	LastAudioExec.setTime(LastAudioExec.getTime() - (2000));
	continueCountdown 	= true;
	TurboText 			= (getCookieValue("turbo") === "") ? ("Turbo") : ("Slow down");
	RightNow			= RightNow.toUTCString();
	
	if (document.querySelectorAll("table .btn.btn-primary").length > 1)
		current = document.querySelector("head");
	for(var i = Places.length; i--; arr.unshift(Places[i]));
	if (current != document.querySelector("head"))
	{
		current.style.outline = "rgb(129, 129, 129) solid 2px";
		current.querySelectorAll("td").forEach(function(e) {e.style.border = "none";});
		currentID = parseInt(arr.indexOf(current.querySelector("td:nth-child(2)")));
	}
	else
		currentID = -1;
	if (currentID < 0) {
		currentDate = "";
		currentID = Places.length - 1;
	}
	else if (currentID > getElementIndex(current))
		currentID = getElementIndex(current);
	
	var notice;
	var customTitle;
	var refreshText;
	var checkinText;
	var display;
	
	current.scrollIntoView();
	display = "";
	refreshText = "Stop refresh";
	checkinText = "Automatic (enabled)";
	if (getCookieValue("stopRefresh") == "1")
		refreshText = "Start refresh";
	if (getCookieValue("manualCheckin") == "1")
		checkinText = "Manual (enabled)";
	if (currentDate !== "")
		document.title = currentDate;
	
	notice 				= document.querySelector("#false");
	notice.outerHTML 	= notice.outerHTML + '<h1 id="custom-title" style="font-size: 65px;">' + currentDate + '</h1>';
	
	if (currentID == Places.length - 1)
		display = 'style="display: none;"';
	customTitle 			= document.querySelector("#custom-title");
	customTitle.outerHTML 	= customTitle.outerHTML + '<button class="btn" ' + display + ' onclick="Turbo()" id="turbo">'+ TurboText + '</button> <button class="btn" onclick="StopRefresh()" id="refresh">' + refreshText + '</button> <button class="btn" onclick="ManualCheckin()" id="checkinManual">' + checkinText + '</button>';
	
	turboButton = document.querySelector("#turbo");
	if (getCookieValue("alert") !== "" || getCookieValue("playsound") !== "") 
		turboButton.outerHTML = turboButton.outerHTML + ' <button class="btn" onclick="RemoveAlert()">Remove alerts</button>';
	turboButton = document.querySelector("#turbo");
	
	if (getCookieValue("playsound") !== "")
	{
		PlayAudio('http://noproblo.dayjo.org/ZeldaSounds/WW_New/WW_Fanfare_HeartContainer.wav', 0.7);
		window.open("https://youtu.be/SB1VqLCTFpA?t=20m18s");
	}
	
	if (getCookieValue("alert") !== "") {
		customTitle 					= document.querySelector("#custom-title");
		customTitle.style.background 	= "yellow";
		customTitle.style.lineHeight	= "60px";
		document.title				 	= "(1) " + currentDate;
	}

	if (getCookieValue("stopRefresh") != "1")
	    Countdown(getCookieValue("turbo") === "" ? (10 + random(1.5)) : (3 + random(3)));
	

	checkFreeCheckin();
	updateCheckinStats(0);
}
Init();


function checkFreeCheckin() {
	for(i = 0; i <= currentID; i++)
	{
		var nbrPlaces;
		var parent;
		
		nbrPlaces 	= parseInt(Places[i].innerText);
		parent 		= Places[i].parentElement;
		if (parent != current && nbrPlaces > 0)
		{
			if (parent.querySelector(":nth-child(5)").innerText === "") {
				if (getCookieValue("manualCheckin") === "")
				{
					document.querySelector("table .btn.btn-primary").click();
				}
			}
			else {
				if (getCookieValue("manualCheckin") === "")
				{
					parent.querySelector(":nth-child(5) a").click();
					document.cookie = "playsound=1;expires=" + twosec.toUTCString();
				}
				document.cookie = "alert=1;expires=" + tenmin.toUTCString();
			}
			break;
		}
		else if (parent != current)
		{
			parent.style.opacity = 1 - (0.35 * (i / 3));
			parent.querySelectorAll("td").forEach(SetBlack);
		}
		else
			break;
	}
}

function updateCheckinStats(x = -1) {
	if (x > -1)
		i = x;
	while (i < Places.length)
	{
		var oldNbr;
		var newNbr;
		var newText;
		var newColor;
		
		oldNbr 						= parseInt(getCookieValue("p" + i));
		newNbr 						= parseInt(Places[i].innerText);
		document.cookie 			= "p" + i + "=" + newNbr;
		Places[i].style.opacity		= 0.7;
		newText 					= "";
		newColor 					= "grey";
		
		if (oldNbr > newNbr || (isNaN(newNbr) && oldNbr > 0) || getCookieValue("c" + i) < 0)
		{
			if (oldNbr > newNbr || (isNaN(newNbr) && oldNbr > 0))
			{
				document.cookie = "c" + i + "=-1;expires=" + tenmin.toUTCString();
				PlayAudio('http://noproblo.dayjo.org/ZeldaSounds/WW_New/WW_PictoBox_Erase.wav', 0.2);
			}
			newText  = '▼ ';
			newColor = "red";
		}
		else if (oldNbr < newNbr || (newNbr > 0 && isNaN(oldNbr)) || getCookieValue("c" + i) > 0)
		{
			if (oldNbr < newNbr || (newNbr > 0 && isNaN(oldNbr)))
			{
				document.cookie = "c" + i + "=1;expires=" + tenmin.toUTCString();
				PlayAudio('http://noproblo.dayjo.org/ZeldaSounds/WW_New/WW_PictoBox_Save.wav', 0.2);
			}
			newText  = '▲ ';
			newColor = "green";
		}
		
		Places[i].innerText		= newText + Places[i].innerText;
		Places[i].style.color 	= newColor;
		i++;
	}
}
