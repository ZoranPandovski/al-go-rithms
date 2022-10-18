// Global Map for Pass by Reference
let nameData = new Map();
// Execute When the Extension Button Is Clicked
chrome.browserAction.onClicked.addListener(function(activeTab) {
  chrome.tabs.create({ url: "index.html" });
});
// Meme Data
document.addEventListener('DOMContentLoaded', function() {
  document.getElementById("memeButton").addEventListener("click", createMeme);
  getMemeNames('https://memegen.link/api/templates/');
});
// Get Meme Titles and URLs from the API
function getMemeNames(url) {
  nameData.clear();
  let memeNames = [];
  let xhr = new XMLHttpRequest();
  xhr.open('GET', url);
  xhr.responseType = 'json';
  xhr.onload = function() {
    if (xhr.status == 200) {
      memeLinkData = xhr.response;
      let keys = Object.keys(memeLinkData);
      let vals = Object.values(memeLinkData);
      for (var i = 0; i < keys.length; i++) {
        memeNames[i] = keys[i];
        nameData.set(keys[i], vals[i]);
      }
      displayNames(memeNames);
    }
  };
  xhr.send();
}
// Run Function on Button Click
function createMeme() {
  document.getElementById("fakeProgress").style.display = "block";
  let top = document.getElementById("topText").value;
  let bottom = document.getElementById("bottomText").value;
  let imgName = document.getElementById("image").value;
  let imgCode = nameData.get(imgName);
  const regex = /[a-z\-]*$/gm;
  let img = regex.exec(imgCode);
  document.getElementById("imgOut").innerHTML = '<img id="meme" src="https://memegen.link/'+img+'/'+encodeURIComponent(top)+'/'+encodeURIComponent(bottom)+'.jpg" />';
  checkImage();
}
// Load the Titles from the API
function displayNames(memeNames) {
  select = document.getElementById('image');
  for (let i = 0; i < memeNames.length; i++) {
    let opt = document.createElement('option');
    opt.value = memeNames[i];
    opt.innerHTML = memeNames[i];
    select.appendChild(opt);
  }
}
// Hide the Progress Bar After Image Loads
function checkImage() {
  if (document.getElementById("meme").complete) {
    document.getElementById("fakeProgress").style.display = "none";
  } 
  else {
    setTimeout(checkImage, 100);
  }
}