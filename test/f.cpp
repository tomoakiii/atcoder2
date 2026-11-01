setInterval(() => {
document.querySelectorAll('video').forEach(video => {
if (video.paused) video.play();
});
}, 1000); // 1秒ごとにチェックして自動再生