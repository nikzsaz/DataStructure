var arr1 = [12,23,34];
var arr2 = [34,5,4];

var arr = new Object();

for(var i = 0 ; i < 3 ; i++){
	arr[i] = new Object();
    arr[i]["first"] = arr1[i];
    arr[i]["second"] = arr2[i];
}

for(var i = 0 ; i < 3 ; i++){
	document.write(arr[i].first + " - >  " +arr[i].second + "</br>");
}

