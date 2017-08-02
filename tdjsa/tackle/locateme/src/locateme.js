const createURL = function(latitude, longitude) {
	if (latitude == void(0) || longitude == void(0)) return ''
	return `https://google.com?q=${latitude},${longitude}`
}

const setLocation = (window, url) => {
	window.location = url
}

const locate = () => {
	navigator.geolocation.getCurrentPosition(onSuccess, onError)
}

const onError = (error) => {
	document.getElementById('error').innerHTML = error.message
}

const onSuccess = ({ coords }) => {
	const { latitude, longitude } = coords
	const url = createURL(latitude, longitude)
	setLocation(window, url)
}