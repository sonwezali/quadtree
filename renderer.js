const canvas = document.getElementById('myCanvas')
const ctx = canvas.getContext('2d')

canvas.width = window.innerWidth
canvas.height = window.innerHeight

const squareSize  = canvas.height / 1.25
const pointRadius = 10

const squareStartX = (canvas.width  - squareSize) / 2
const squareStartY = (canvas.height - squareSize) / 2

document.body.style.background = '#181818';

const drawCircle = (x, y, radius, color) => {
    ctx.beginPath()
    ctx.arc(x, y, radius, 0, Math.PI * 2)
    ctx.fillStyle = color
    ctx.fill()
    ctx.closePath()
}

const initialSquare = (x, y, w) => {
    ctx.strokeStyle = '#FF00E5'
    ctx.rect(x, y, w, w)
    ctx.stroke()
}

const isIn = (x, y) => {
    return (x < (squareStartX + squareSize - pointRadius) && x > (squareStartX + pointRadius) && y < (squareStartY + squareSize - pointRadius) && y > (squareStartY + pointRadius))
}

initialSquare(squareStartX, squareStartY, squareSize)

canvas.addEventListener('click', (event) => {
    const x = event.clientX
    const y = event.clientY
    if (isIn(x, y)) {
        const randColor = `hsl(${Math.random() * 360}, 70%, 50%)`
        drawCircle(x, y, pointRadius, randColor)
    }
})